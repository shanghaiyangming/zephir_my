namespace My\Mongo;

class Collection
{
    private _client = null;

    private _collection {
        set, get
    };

    private _collectionName {
        set, get
    };

    private _databaseName = "ICCv1" {
        set, get
    };

    private _clusterName = "defaultOptions" {
        set, get
    };

    private _collectionOptions = [] {
        set, get
    };

    private _db = null;

    private _admin = null;

    private _backup = null;

    private _mapreduce = null;

    private _fs = null;

    private _queryHaystack = [
        "$and",
        "$or",
        "$nor",
        "$not",
        "$where"
    ];

    private _updateHaystack = [
        "$set",
        "$inc",
        "$unset",
        "$rename",
        "$setOnInsert",
        "$addToSet",
        "$pop",
        "$pullAll",
        "$pull",
        "$pushAll",
        "$push",
        "$each",
        "$slice",
        "$sort",
        "$bit",
        "$isolated"
    ];

    private _noAppendQuery = false {
        set,get
    };

    const TIMEOUT = 6000000;

    const USLEEP = 50000;

    const RETRY = 3;

    const FSYNC = false;

    const UPSERT = false;

    const MULTIPLE = true;

    const JUSTONE = false;

    const DEBUG = false;

    const GRIDFS_PREFIX = "icc_";

    const DB_MAPREDUCE = "mapreduce";


    public function __construct(string! collectionName, string! databaseName = null, string! clusterName = null, array! collectionOptions = null) {
        let this->_collectionName = collectionName;
        let this->_databaseName = empty databaseName ? "ICCv1" : databaseName;
        let this->_clusterName = empty clusterName ? "defaultOptions" : clusterName;
        let this->_collectionOptions = empty collectionOptions ? [] : collectionOptions;
    }

    public function setMongoClient(<\MongoClient> client) -> boolean
    {
        let this->_client = client;
        this->initCollection();
        return true;
    }

    public function getMongoClient() -> <\MongoClient> 
    {
        return this->_client;
    }

    private function initCollection() -> <\MongoCollection>
    {
        this->initDB();
        let this->_collection = this->_client->selectCollection(this->_databaseName,this->_collectionName);
        return this->_collection;
    }

    private function initDB() -> void
    {
        if empty this->_client  {
            throw new \Exception("please invoke method setMongoClient before initDB");
        } 
        let this->_db = this->_client->selectDB(this->_databaseName);
    }

    private function initAdmin() -> void
    {
        if empty this->_client  {
            throw new \Exception("please invoke method setMongoClient before initAdmin");
        } 

        if empty this->_admin {
            let this->_admin = this->_client->selectDB("admin");
        }
    }

    private function initBackup() -> void
    {
        if empty this->_client  {
            throw new \Exception("please invoke method setMongoClient before initBackup");
        } 

        if empty this->_backup {
            let this->_backup = this->_client->selectDB("backup");
        }
    }

    private function initMapreduce() -> void
    {
        if empty this->_client  {
            throw new \Exception("please invoke method setMongoClient before initMapreduce");
        } 

        if empty this->_mapreduce {
            let this->_mapreduce = this->_client->selectDB("mapreduce");
        }
    }

    private function initGridFs()  -> void
    {
        if empty this->_client  {
            throw new \Exception("please invoke method setMongoClient before init");
        } 
        if empty this->_db  {
            throw new \Exception("please invoke method initdb before initGridFs");
        } 

        if empty this->_fs {
            if class_exists("\MongoGridFS") {
                let this->_fs = new \MongoGridFS(this->_db, self::GRIDFS_PREFIX);
            };
        }
    }

    private function appendQuery(array! query = null) -> array
    {
        if empty query {
            let query = [];
        }

        if this->_noAppendQuery {
            return query;
        }

        array keys = [];
        array intersect = [];

        if typeof query == "array" {
            let keys = (array) array_keys(query);
            let intersect = (array) array_intersect(keys, this->_queryHaystack);
        }

        if ! empty intersect {
            let query = [
                "$and" : [
                    query,
                    [
                        "__REMOVED__" : false
                    ]
                ]
            ];
        } else {
            let query["__REMOVED__"] = false;
        }
        return query;
    }

    private function checkKeyExistInArray(array! arr, keys) -> boolean
    {
        if typeof keys == "string" {
            let keys = [keys];
        }

        var key;
        var items;
        for key, items in arr {

            if in_array(key, keys, true) {
                return true;
            }

            if typeof items == "array" {
                if this->checkKeyExistInArray(items, keys) {
                    return true;
                }
            } 
        }

        return false;
    }

    private function addSharedKeyToQuery(array query = null) -> array
    {
        if typeof query != "array" {
             throw new \Exception("query must be array");
        };
        
        if (this->checkKeyExistInArray(query, "_id")) {
            return query;
        }
        
        array keys = [];
        array intersect = [];

        let keys = (array) array_keys(query);
        let intersect = (array) array_intersect(keys, this->_queryHaystack);

        if ! empty intersect {
            let query = [
                "$and" : [
                    [
                        "_id" : new \MongoId()
                    ],
                    query
                ]
            ];
        } else {
            let query["_id"] = new \MongoId();
        }
        return query;
    }

    private function search(string text) -> <\MongoRegex>
    {
        return new \MongoRegex("/" . preg_replace("/[\s\r\t\n]/", ".*", text) . "/i");
    }

    public function aggregate(array! pipeline)
    {
        if !this->_noAppendQuery {
            if isset pipeline[0]["$geoNear"] {
                var first;
                let first = array_shift(pipeline);
                array_unshift(pipeline, [
                    "$match" : [
                        "__REMOVED__" : false
                    ]
                ]);
                array_unshift(pipeline, first);
            } elseif isset pipeline[0]["$match"] {
                var firstMatch;
                let firstMatch = pipeline[0]["$match"];
                let pipeline[0]["$match"] = this->appendQuery(firstMatch);
            } else {
                array_unshift(pipeline, [
                    "$match" : [
                        "__REMOVED__" : false
                    ]
                ]);
            }
        }
        
        if typeof pipeline != "array" {
            throw new \Exception("pipeline must be an array");
        }

        return this->_collection->aggregate(pipeline);

    }

    public function aggregateCursor(array! command , array! options = []) -> <\MongoCommandCursor>
    {
        if !this->_noAppendQuery {
            if isset command[0]["$geoNear"] {
                var first;
                let first = array_shift(command);
                array_unshift(command, [
                    "$match" : [
                        "__REMOVED__" : false
                    ]
                ]);
                array_unshift(command, first);
            } elseif isset command[0]["$match"] {
                var firstMatch;
                let firstMatch = command[0]["$match"];
                let command[0]["$match"] = this->appendQuery(firstMatch);
            } else {
                array_unshift(command, [
                    "$match" : [
                        "__REMOVED__" : false
                    ]
                ]);
            }
        }

        if typeof command != "array" {
            throw new \Exception("pipeline must be an array");
        }
        return this->_collection->aggregateCursor(command, options);

    }

    public function batchInsert(array! documents, array options = null)
    {
        var row;
        for row in documents {
            let row["__CREATE_TIME__"] = new \MongoDate();
            let row["__MODIFY_TIME__"] = new \MongoDate();
            let row["__REMOVED__"] = false;
        };

        return this->_collection->batchInsert(documents, options);
    }

    public function count(array! query = null, limit = null, skip = null)
    {
        let query = this->appendQuery(query);
        var rst;
        let rst = this->_collection->count(query, limit, skip);
        return rst;
    }

    public function distinct(string! key, array! query = null)
    {
        let query = this->appendQuery(query);
        var rst;
        let rst = this->_collection->distinct(key, query);
        return rst;
    }

    public function drop()
    {
        var targetCollection,target,cursor,row;
        let targetCollection = "bak_" . date("YmdHis") . "_" . this->_collectionName;
        this->initBackup();
        let target = new \MongoCollection(this->_backup, targetCollection);
        let cursor = this->find([]);
        while (cursor->hasNext()) {
            let row = cursor->getNext();
            let row["__OLD_ID__"] = row["_id"];
            unset(row["_id"]);
            target->insert(row, [
                "w" : 0
            ]);
        }

        var rst;
        let rst = this->_collection->drop();
        return rst;
    }

    public function physicalDrop()
    {
        var rst;
        let rst = this->_collection->drop();
        return rst;
    }

    public function ensureIndex(array! keys, array! options = null)
    {
        var rst;
        let rst = this->createIndex(keys, options);
        return rst;
    }

    public function createIndex(array! keys, array! options = null)
    {
        if unlikely this->checkIndexExist(keys) == true {
            return true;
        }
        var defaultOptions;
        let defaultOptions = [];
        let defaultOptions["background"] = true;
        let defaultOptions["w"] = 0;
        let options = (options === null) ? defaultOptions : array_merge(defaultOptions, options);
        var rst;
        if version_compare(\MongoClient::VERSION, "1.5.0", ">=") {
            let rst = this->_collection->createIndex(keys, options);
        } else {
            let rst = this->_collection->ensureIndex(keys, options);
        }
        return rst;
    }

    public function deleteIndex(keys)
    {
        var rst;
        let rst = this->_collection->deleteIndex(keys);
        return rst;
    }

    public function deleteIndexes()
    {
        var rst;
        let rst = this->_collection->deleteIndexes();
        return rst;
    }

    public function checkIndexExist(array! keys) ->boolean
    {
        var indexes,index;
        let indexes = this->_collection->getIndexInfo();
        if ! empty indexes && is_array(indexes) {
            for index in indexes {
                if index["key"] == keys {
                    return true;
                }
            }
        }
        return false;
    }

    public function find(array! query = [], array! fields = []) -> <\MongoCursor>
    {
        var cursor;
        let query = this->appendQuery(query);
        if typeof query != "array" {
            throw new Exception("Find parameters must be an array");
        }

        //zephir生成变量是的递归错误
        var fieldsSetting;
        let fieldsSetting = [];
        if !empty fields {
            var k,v;
            for k,v in fields {
                let fieldsSetting[k] = is_bool(v) ? v : true;
            }
        }
        let cursor = this->_collection->find(query,fieldsSetting);
        
        if !(cursor instanceof \MongoCursor) {
            throw new \Exception("cursor is not \MongoCursor");
        }

        if !(cursor instanceof \Traversable) {
           throw new \Exception("cursor is not \Traversable");     
        }

        return cursor;
    }

    public function findOne(array! query = [], array! fields = [])
    {
        var rst;
        let fields = empty fields  ? [] : fields;
        let query = this->appendQuery(query);
        let rst = this->_collection->findOne(query,fields);
        return rst;
    }

    public function findAll(array! query = [], array! sort = ["_id":1], int skip = 0, int limit = 0, array! fields = []) -> array
    {
        let query = this->appendQuery(query);
        let fields = empty fields ? [] : fields;
        var cursor;
        let cursor = this->_collection->find(query, fields);
        if !(cursor instanceof \MongoCursor) {
            throw new \Exception("query error:" . json_encode(query));
        }
        
        if !empty sort {
            cursor->sort(sort);
        }
            
        if skip > 0 {
            cursor->skip(skip);
        }
        
        if limit > 0 {
            cursor->limit(limit);
        }
        
        if cursor instanceof \Traversable {
            var result;
            let result = iterator_to_array(cursor, false);
            return result;
        }
        
        return [];
    }

    public function findAndModify(array! query, array! update = null, array! fields = null, array! options = null, int count=0)
    {
        //加锁
        var objlock;
        var arrKey,strKey;
        let arrKey = [];
        let arrKey[] = this->_collectionName;
        let arrKey[] = this->_databaseName;
        let arrKey[] = this->_clusterName;
        let arrKey[] = "findAndModify";
        let arrKey[] = query;
        let arrKey[] = update;
        let arrKey[] = fields;
        let arrKey[] = options;
        let strKey = md5(serialize(arrKey));
        let objlock = new \My\Utils\Lock(strKey);
        if unlikely objlock->lock() == true {
            if count < self::RETRY {
                usleep(self::USLEEP);
                let count++;
                return this->findAndModify(query, update, fields, options, count);
            } else {
                return this->failure(599,"current op is locked,please wait.");
            }
        }

        let query = this->appendQuery(query);
        if this->_collection->count(query) == 0 && !empty options["upsert"] {
            let query = this->addSharedKeyToQuery(query);
        } else {
            unset(options["upsert"]);
        }
        var rst;
        let rst = this->_collection->findAndModify(query, update, fields, options);
        return rst;
    }

    public function findAndModifyByCommand(array! option, array! collection = null)
    {
        var cmd,targetCollection;
        let cmd = [];
        let targetCollection = collection === null ? this->_collection : collection;
        let cmd["findandmodify"] = targetCollection;
        if isset option["query"] {
            let cmd["query"] = this->appendQuery(option["query"]);
        }
        if isset option["sort"] {
            let cmd["sort"] = option["sort"];
        }
        if isset option["remove"] {
            let cmd["remove"] = is_bool(option["remove"]) ? option["remove"] : false;
        }
        if isset option["update"] { 
            let cmd["update"] = option["update"];
        }
        if isset option["new"] {
            let cmd["new"] = is_bool(option["new"]) ? option["new"] : false;
        }
        if isset option["fields"] {
            let cmd["fields"] = option["fields"];
        }
        if isset option["upsert"] {
            let cmd["upsert"] = is_bool(option["upsert"]) ? option["upsert"] : false;
        }
        if this->_collection->count(cmd["query"]) == 0 && !empty option["upsert"] {
            let cmd["query"] = this->addSharedKeyToQuery(cmd["query"]);
        } else {
            unset(cmd["upsert"]);
        }

        var rst;
        let rst = this->_db->command(cmd);
        return rst;
    }

    public function insertRef(array! a, array! options = null)
    {
        var rst;
        let rst = this->insertByFindAndModify(a);
        if isset rst["ok"] {
            return false;
        }
        return rst;
    }

    public function insert(array! a, array! options = null)
    {
        if empty a {
            throw new \Exception("object is null");
        }
        
        var defaultOptions = [];
        let defaultOptions["fsync"] = self::FSYNC;
        let options = (options === null) ? defaultOptions : array_merge(defaultOptions, options);
        
        let a = this->array_unset_recursive(a, [
            "__CREATE_TIME__",
            "__MODIFY_TIME__",
            "__REMOVED__"
        ]);
        
        if !isset a["__CREATE_TIME__"] {
            let a["__CREATE_TIME__"] = new \MongoDate();
        }
        
        if !isset a["__MODIFY_TIME__"] {
            let a["__MODIFY_TIME__"] = new \MongoDate();
        }
        
        if !isset a["__REMOVED__"] && !this->_noAppendQuery {
            let a["__REMOVED__"] = false;
        }
        
        var rst;
        let rst = this->_collection->insert(a, options);
        return rst;
    }

    public function insertByFindAndModify(a)
    {
        if empty a {
            throw new \Exception("a is null");
        }

        var query,fields,options;
        let a = this->array_unset_recursive(a, [
            "_id",
            "__CREATE_TIME__",
            "__MODIFY_TIME__",
            "__REMOVED__"
        ]);

        if !isset a["__CREATE_TIME__"] {
            let a["__CREATE_TIME__"] = new \MongoDate();
        }
        
        if !isset a["__MODIFY_TIME__"] {
            let a["__MODIFY_TIME__"] = new \MongoDate();
        }
        
        if !isset a["__REMOVED__"] {
            let a["__REMOVED__"] = false;
        }
        
        let query = [
            "_id" : new \MongoId()
        ];

        var arr = [];
        let arr["$set"] = a;
        let fields = null;
        let options = [
            "new" : true,
            "upsert" : true
        ];
        
        var rst;
        let rst = this->findAndModify(query, arr, fields, options);
        return rst;
    }

    public function remove(array! criteria = null, array! options = null)
    {
        if criteria === null {
            throw new \Exception("criteria is null");
        }
        
        var defaultOptions = [];
        let defaultOptions = [
            "justOne" : self::JUSTONE,
            "fsync" : self::FSYNC
        ];
        
        let options = (options === null) ? defaultOptions : array_merge(defaultOptions, options);
        
        if isset options["justOne"] && !options["justOne"] {
            let options["multiple"] = true;
        }
        
        let criteria = this->appendQuery(criteria);
        var rst;
        let rst = this->_collection->update(criteria, [
            "$set" : [
                "__REMOVED__" : true
            ]
        ], options);
        return rst;
    }

    public function physicalRemove(array! criteria = null, array options = null)
    {
        if criteria === null {
            throw new \Exception("criteria is null");
        }
        
        var defaultOptions = [];
        let defaultOptions = [
            "justOne" : self::JUSTONE,
            "fsync" : self::FSYNC
        ];
        
        let options = (options === null) ? defaultOptions : array_merge(defaultOptions, options);
        var rst;
        let rst = this->_collection->remove(criteria, options);
        return rst;
    }

    public function physicalUpdate(criteria, obj, array options = null)
    {
        if !is_array(criteria) {
            throw new \Exception("criteria is array");
        }
        
        if empty obj {
            throw new \Exception("obj is empty");
        }
        
        var key,keys,defaultOptions;
        let keys = array_keys(obj);
        for key in keys {
            if !in_array(key, this->_updateHaystack, true) {
                throw new \Exception("key must contain " . join(",", this->_updateHaystack));
            }
        }
        
        let defaultOptions = [
            "upsert" : self::UPSERT,
            "multiple" : self::MULTIPLE,
            "fsync" : self::FSYNC
        ];
        
        let options = (options === null) ? defaultOptions : array_merge(defaultOptions, options);
        var rst;
        let rst = this->_collection->update(criteria, obj, options);
        return rst;
    }

    public function update(criteria, obj, array options = null,int count = 0)
    {
        if !is_array(criteria) {
            throw new \Exception("criteria is array");
        }
        
        if empty obj {
            throw new \Exception("object is empty");
        }

        var objlock;
        var arrKey,strKey;
        let arrKey = [];
        let arrKey[] = this->_collectionName;
        let arrKey[] = this->_databaseName;
        let arrKey[] = this->_clusterName;
        let arrKey[] = "update";
        let arrKey[] = criteria;
        let arrKey[] = obj;
        let arrKey[] = options;
        let strKey = md5(serialize(arrKey));
        let objlock = new \My\Utils\Lock(strKey);
        if unlikely objlock->lock() == true {
            if count < self::RETRY {
                usleep(self::USLEEP);
                let count++;
                return this->update(criteria, obj, options, count);
            } else {
                return this->failure(599,"current op is locked,please wait.");
            }
        }
        
        var key,keys,defaultOptions;
        let keys = array_keys(obj);
        for key in keys {
            if !in_array(key, this->_updateHaystack, true) {
                throw new \Exception("key must contain " . join(",", this->_updateHaystack));
            }
        }
        let defaultOptions = [
            "upsert" : self::UPSERT,
            "multiple" : self::MULTIPLE,
            "fsync" : self::FSYNC
        ];
        
        let options = (options === null) ? defaultOptions : array_merge(defaultOptions, options);
        
        let criteria = this->appendQuery(criteria);
        let obj = this->array_unset_recursive(obj, [
            "_id",
            "__CREATE_TIME__",
            "__MODIFY_TIME__",
            "__REMOVED__"
        ]);
        
        if (unlikely this->_collection->count(criteria) == 0) {
            if isset options["upsert"] && options["upsert"] {
                let criteria = this->addSharedKeyToQuery(criteria);
                this->_collection->update(criteria, [
                    "$set" : [
                        "__CREATE_TIME__" : new \MongoDate(),
                        "__MODIFY_TIME__" : new \MongoDate(),
                        "__REMOVED__" : false
                    ]
                ], options);
            }
        } else {
            unset(options["upsert"]);
            this->_collection->update(criteria, [
                "$set" : [
                    "__MODIFY_TIME__" : new \MongoDate()
                ]
            ], options);
        }
        
        var rst;
        let rst = this->_collection->update(criteria, obj, options);
        return rst;
    }

    public function save(array! a, array! options = null)
    {
        return this->saveRef(a,options);
    }

    public function saveRef(array! a, array! options = null)
    {
        if !isset a["__CREATE_TIME__"] {
            let a["__CREATE_TIME__"] = new \MongoDate();
        }
        let a["__REMOVED__"] = false;
        let a["__MODIFY_TIME__"] = new \MongoDate();
        var rst;
        let rst = this->_collection->save(a, options);
        if isset rst["ok"] && rst["ok"]==1 {
            return a;
        } else {
            return rst;
        }
        
    }

    public function command(array! command)
    {
        var rst;
        let rst = this->_collection->db->command(command);
        return rst;
    }

    private function failure(int! code, string! msg) -> array
    {
        if is_array(msg) {
           let msg = json_encode(msg);
        }

        return [
            "ok" : 0,
            "code" : code,
            "msg" : msg,
            "err": msg,
            "errmsg" : msg
        ];
    }

    public function mapReduce(string out = null, map, reduce, array! query = [], finalize = null, string! method = "replace", scope = null, sort = null, limit = null)
    {
        var arrArgs, rst, command, objlock, outMongoCollection;
        if (out == null) {
            let arrArgs = func_get_args();
            let out = md5(serialize(arrArgs));
        }

        let objlock = new \My\Utils\Lock(out);
        if objlock->lock() {
            return this->failure(599,"current op is locked,please wait.");
        }
    
        // map reduce执行锁管理结束
        let command = [];
        let command["mapreduce"] = this->_collection;
        let command["map"] = (map instanceof \MongoCode) ? map : new \MongoCode(map);
        let command["reduce"] = (reduce instanceof \MongoCode) ? reduce : new \MongoCode(reduce);
        let query = this->appendQuery(query);
        if !empty query {
            let command["query"] = query;
        }
        
        if !empty finalize {
            let command["finalize"] = (finalize instanceof \MongoCode) ? finalize : new \MongoCode(finalize);
        }
        if !empty sort {
            let command["sort"] = sort;
        }
        if !empty limit {
            let command["limit"] = limit;
        }
        if !empty scope {
            let command["scope"] = scope;
        }
        let command["verbose"] = true;
        
        if !in_array(method, [
            "replace",
            "merge",
            "reduce"
        ], true) {
            let method = "replace";
        }
        
        let command["out"] = [
            method : out,
            "db" : self::DB_MAPREDUCE,
            "sharded" : false,
            "nonAtomic" : in_array(method, [
                "merge",
                "reduce"
            ], true) ? true : false
        ];
        
        //this->_collection->db->setReadPreference(\MongoClient::RP_SECONDARY);
        let rst = this->_collection->db->command(command);
        
        if isset rst["ok"] && rst["ok"] == 1 {
            let outMongoCollection = new self(out, self::DB_MAPREDUCE, this->_clusterName);
            outMongoCollection->setMongoClient(this->_client);
            outMongoCollection->setNoAppendQuery(true);
            return outMongoCollection;
        } else {
            return this->failure(501, rst);
        }
    }

    public function storeToGridFS(string! fieldName, array! metadata = [])
    {
        var finfo,mime,id,gridfsFile;
        if !is_array(metadata) {
            let metadata = [];
        }
        
        if !isset _FILES[fieldName] {
            throw new \Exception("_FILES[fieldName]无效");
        }
        
        let metadata = array_merge(metadata, _FILES[fieldName]);
        let finfo = finfo_open(FILEINFO_MIME);
        let mime = finfo_file(finfo, _FILES[fieldName]["tmp_name"]);
        if mime !== false {
            let metadata["mime"] = mime;
        }
        
        this->initGridFS();
        let id = this->_fs->storeUpload(fieldName, metadata);
        let gridfsFile = this->_fs->get(id);
        if !(gridfsFile instanceof \MongoGridFSFile) {
            throw new \Exception("gridfsFile is not instanceof MongoGridFSFile");
        }
        
        var rst;
        let rst = gridfsFile->file;
        return rst;
    }

    public function storeBytesToGridFS(bytes, string! filename = "", array! metadata = [])
    {
        var finfo,mime,id,gridfsFile;
        if !is_array(metadata) {
            let metadata = [];
        }
        
        if !empty filename {
            let metadata["filename"] = filename;
        }
        
        let finfo = finfo_open(FILEINFO_MIME);
        let mime = finfo_buffer(finfo,bytes);
        if mime !== false {
            let metadata["mime"] = mime;
        }

        this->initGridFS();
        let id = this->_fs->storeBytes(bytes, metadata);
        let gridfsFile = this->_fs->get(id);
        var rst;
        let rst = gridfsFile->file;
        return rst;
    }

    public function getGridFsFileById(id)
    {
        if !(id instanceof \MongoId) {
            let id = new \MongoId(id);
        }
        
        this->initGridFS();
        var rst;
        let rst = this->_fs->get(id);
        return rst;
    }

    /**
     * 根据查询条件获取指定数量的结果集
     *
     * @param array query            
     * @param number start            
     * @param number limit            
     * @return multitype:
     */
    public function getGridFsFileBy(array! query, array! sort = ["_id":-1], int start = 0, int limit = 20, array! fields = [])
    {
        if !is_array(query) {
            let query = [];
        }
        this->initGridFS();
        var cursor,rst;
        let cursor = this->_fs->find(query, fields);
        cursor->sort(sort);
        cursor->skip(start);
        cursor->limit(limit);
        let rst = iterator_to_array(cursor, false);
        return rst;
    }

    /**
     * 获取GridFS对象
     *
     * @return \MongoGridFS
     */
    public function getGridFS()
    {
        this->initGridFS();
        return this->_fs;
    }

    /**
     * 根据ID获取文件的信息
     *
     * @param string id            
     * @return array 文件信息数组
     */
    public function getInfoFromGridFS(id) -> array
    {
        
        if !(id instanceof \MongoId) {
            let id = new \MongoId(id);
        }
        this->initGridFS();
        var gridfsFile;
        let gridfsFile = this->_fs->get(id);
        return gridfsFile->file;
    }

    /**
     * 根据ID获取文件内容，二进制
     *
     * @param string id            
     * @return bytes
     */
    public function getFileFromGridFS(id)
    {
        if !(id instanceof \MongoId) {
            let id = new \MongoId(id);
        }
        this->initGridFS();
        var gridfsFile;
        let gridfsFile = this->_fs->get(id);
        if gridfsFile instanceof \MongoGridFSFile {
            return gridfsFile->getBytes();
        } else {
            return false;
        }
    }

    /**
     * 删除陈旧的文件
     *
     * @param mixed id
     *            \MongoID or String
     * @return bool true or false
     */
    public function removeFileFromGridFS(id)
    {
        if !(id instanceof \MongoId) {
            let id = new \MongoId(id);
        }
        this->initGridFS();
        var rst;
        let rst = this->_fs->remove([
            "_id" : id
        ]);
        return rst;
    }


    public function array_unset_recursive(array! arr, array! fields, boolean remove = true)
    {
        var key,value;
        for key,value in arr {
            if remove {
                if in_array(key, fields, true) {
                    unset(arr[key]);
                } else {
                    if is_array(value) {
                        let arr[key] = this->array_unset_recursive(value, fields, remove);
                    }
                }
            } else {
                if !in_array(key, fields, true) {
                    unset(arr[key]);
                } else {
                    if is_array(value) {
                        let arr[key] = this->array_unset_recursive(value, fields, remove);
                    }
                }
            }
        }

        return arr;
    }


    /**
     * 打印最后一个错误信息
     */
    public function debug()
    {
        if this->_db instanceof \MongoDB {
            var err;
            let err = this->_db->lastError();
            return err;
        }
    }

    public function __call(string! method, arguments) {
        var rst;
        let rst = call_user_func_array([this->_collection,method],arguments);
        return rst;
    }

    /**
     * 在析构函数中调用debug方法
     */
    public function __destruct()
    {}

}