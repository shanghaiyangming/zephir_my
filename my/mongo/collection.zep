namespace My\Mongo;

class Collection
{
	private _client = null;

 	//集合操作对象
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
		"and",
		"or",
		"nor",
		"not",
		"where"
	];

    private _updateHaystack = [
    	"set",
        "inc",
        "unset",
        "rename",
        "setOnInsert",
        "addToSet",
        "pop",
        "pullAll",
        "pull",
        "pushAll",
        "push",
        "each",
        "slice",
        "sort",
        "bit",
        "isolated"
    ];

    private _noAppendQuery = false {
    	set,get
    };

    const TIMEOUT = 6000000;

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
		this->initDB();
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

	/**
	 * 添加查询扩展参数__REMOVED__ 
     *
     */
	private function appendQuery(array! query = null)
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
                    [
                        "__REMOVED__" : false
                    ],
                    query
                ]
            ];
        } else {
            let query["__REMOVED__"] = false;
        }
        return query;
    }


    /**
     * 检查某个数组中，是否包含某个键
     *
     * @param array array            
     * @param array keys            
     * @return boolean
     */
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

    /**
     * ICC采用_id自动分片机制，故需要判断是否增加片键字段，用于分片集合update数据时使用upsert:true的情况
     *
     * @param array query            
     * @return multitype: Ambigous multitype:\MongoId >
     */
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

     /**
     * 处理检索条件
     *
     * @param string text            
     */
    private function search(string text) -> <\MongoRegex>
    {
        return new \MongoRegex("/" . preg_replace("/[\s\r\t\n]/", ".*", text) . "/i");
    }


    /**
     * aggregate框架指令达成
     *
     * @return mixed
     */
    public function aggregate(pipeline)
    {
        if empty this->_noAppendQuery {
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
                // 解决率先执行match:{__REMOVED__:false}导致的性能问题
                let pipeline[0]["match"] = this->appendQuery(pipeline[0]["$match"]);
            } else {
                array_unshift(pipeline, [
                    "$match" : [
                        "__REMOVED__" : false
                    ]
                ]);
            }
        }
        
        return this->_collection->aggregate(pipeline);
    }

    /**
     * 批量插入数据
     *
     * @see MongoCollection::batchInsert()
     */
    public function batchInsert(array! documents, array options = NULL)
    {
        var row;
        for row in documents {
            let row["__CREATE_TIME__"] = new \MongoDate();
            let row["__MODIFY_TIME__"] = new \MongoDate();
            let row["__REMOVED__"] = false;
        };
        return this->_collection->batchInsert(documents, options);
    }

    /**
     * 统计符合条件的数量
     *
     * @see MongoCollection::count()
     */
    public function count(array! query = NULL, limit = NULL, skip = NULL)
    {
        let query = this->appendQuery(query);
        return this->_collection->count(query, limit, skip);
    }

    /**
     * 根据指定字段
     *
     * @param string key            
     * @param array query            
     */
    public function distinct(string! key, array! query = null)
    {
        let query = this->appendQuery(query);
        return this->_collection->distinct(key, query);
    }


    /**
     * 直接禁止drop操作,注意备份表中只包含当前集合中的有效数据，__REMOVED__为true的不在此列
     *
     * 仅适合数据量操作能在脚本生命周期内能够完成的
     *
     * @see MongoCollection::drop()
     */
    public function drop()
    {
        // 做法1：抛出异常禁止Drop操作
        // throw new \Exception("ICC deny execute "drop()" collection operation");
        // 做法2：复制整个集合的数据到新的集合中，用于备份，备份数据不做片键，不做索引以便节约空间，仅出于安全考虑，原有_id使用保留字__OLD_ID__进行保留
        var targetCollection,target,cursor,row;
        let targetCollection = "bak_" . date("YmdHis") . "_" . this->_collectionName;
        this->initBackup();
        let target = new \MongoCollection(this->_backup, targetCollection);
        // 变更为重命名某个集合或者复制某个集合的操作作为替代。
        let cursor = this->find([]);
        while (cursor->hasNext()) {
            let row = cursor->getNext();
            let row["__OLD_ID__"] = row["_id"];
            unset(row["_id"]);
            target->insert(row, [
                "w" : 0
            ]);
        }
        return this->_collection->drop();
    }

    /**
     * 物理删除数据集合
     */
    public function physicalDrop()
    {
        return this->_collection->drop();
    }

        /**
     * 新驱动已经抛弃了该方法，但是为了保持一致性，继续支持，但是不建议采用
     *
     * @see MongoCollection::ensureIndex()
     */
    public function ensureIndex(array! keys, array! options = NULL)
    {
        return this->createIndex(keys, options);
    }

    /**
     * 新的写法，创建索引
     *
     * @param array keys            
     * @param array options            
     */
    public function createIndex(array! keys, array! options = NULL)
    {
        if unlikely this->checkIndexExist(keys) == true {
            return true;
        }
        var defaultOptions;
        let defaultOptions = [];
        let defaultOptions["background"] = true;
        let defaultOptions["w"] = 0;
        let options = (options === NULL) ? defaultOptions : array_merge(defaultOptions, options);
        if version_compare(\MongoClient::VERSION, "1.5.0", ">=") {
            return this->_collection->createIndex(keys, options);
        } else {
            return this->_collection->ensureIndex(keys, options);
        }
    }

    /**
     * 检测集合的某个索引是否存在
     *
     * @param array keys            
     * @return boolean
     */
    public function checkIndexExist(array! keys) ->boolean
    {
        var indexes,index;
        let indexes = this->_collection->getIndexInfo();
        if ! empty(indexes) && is_array(indexes) {
            for index in indexes {
                if index["key"] == keys {
                    return true;
                }
            }
        }
        return false;
    }


    /**
     * 查询符合条件的项目，自动排除__REMOVED__:true的结果集
     *
     * @see MongoCollection::find()
     */
    public function find(array! query = NULL, array! fields = NULL)
    {
        let fields = empty(fields) ? [] : fields;
        let query = this->appendQuery(query);
        return this->_collection->find(query, fields);
    }

    /**
     * 查询符合条件的一条数据
     *
     * @see MongoCollection::findOne()
     */
    public function findOne(array! query = NULL, array! fields = NULL)
    {
        let fields = empty(fields) ? [] : fields;
        let query = this->appendQuery(query);
        return this->_collection->findOne(query, fields);
    }

    /**
     * 获取符合条件的全部数据
     *
     * @param array query            
     * @param array sort            
     * @param int skip            
     * @param int limit            
     * @param array fields            
     * @return array
     */
    public function findAll(array! query = [], array! sort = ["natural":1], int skip = 0, int limit = 0, array! fields = []) -> array
    {
        let fields = empty(fields) ? [] : fields;
        var cursor;
        let cursor = this->find(query, fields);
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

    /**
     * findAndModify操作
     * 特别注意：__REMOVED__ __MODIFY_TIME__ __CREATE_TIME__ 3个系统保留变量在update参数中的使用
     *
     * @param array query            
     * @param array update            
     * @param array fields            
     * @param array options            
     * @return array
     */
    public function findAndModify(array! query, array! update = NULL, array! fields = NULL, array! options = NULL)
    {
        let query = this->appendQuery(query);
        if this->_collection->count(query) == 0 && !empty options["upsert"] {
            let query = this->addSharedKeyToQuery(query);
        } else {
            unset(options["upsert"]);
        }
        return this->_collection->findAndModify(query, update, fields, options);
    }

    /**
     * 增加findAndModify方法
     * 特别注意：__REMOVED__ __MODIFY_TIME__ __CREATE_TIME__ 3个系统保留变量在update参数中的使用
     *
     * @param array option            
     * @param string collection            
     * @return mixed array|null
     */
    public function findAndModifyByCommand(array! option, array! collection = NULL)
    {
        var cmd,targetCollection;
        let cmd = [];
        let targetCollection = collection === NULL ? this->_collection : collection;
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
        return this->_db->command(cmd);
    }

    /**
     * 插入特定的数据,并保持insert第一个参数a在没有_id的时候添加_id属性
     *
     * @param array object            
     * @param array options            
     */
    public function insertRef(a, array! options = NULL)
    {
        var res;
        let res = this->insertByFindAndModify(a);
        if isset res["ok"] {
            return false;
        }
        return res;
    }

    /**
     * 插入特定的数据，注意此方法無法針對a添加_id属性，详见参数丢失原因的文档说明
     * 解决这个问题，请使用上面的方法insertRef
     * 注意因为参数检查的原因，无法直接覆盖insert方法并采用引用，如下原因
     * <b>Strict Standards</b>: Declaration of My\Common\MongoCollection::insert() should be compatible with MongoCollection::insert(array_of_fields_OR_object, array options = NULL)
     *
     * @param array object            
     * @param array options            
     */
    public function insert(array! a, array! options = NULL)
    {
        if empty(a) {
            throw new \Exception("object is NULL");
        }
        
        var defaultOptions = [];
        let defaultOptions["fsync"] = self::FSYNC;
        let options = (options === NULL) ? defaultOptions : array_merge(defaultOptions, options);
        
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
        
        return this->_collection->insert(a, options);
    }

    /**
     * 通过findAndModify的方式，插入数据。
     * 这样可以使用a["a.b"]的方式插入结构为{a:{b:xxx}}的数据,这是insert所不能办到的
     * 采用update也可以实现类似的效果，区别在于findAndModify可以返回插入之后的新数据，更接近insert的原始行为
     *
     * @param array a            
     * @return array
     */
    public function insertByFindAndModify(a)
    {
        if empty a {
            throw new \Exception("a is NULL");
        }

        var query,fields,options;
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
        
        if !isset a["__REMOVED__"] {
            let a["__REMOVED__"] = false;
        }
        
        let query = [
            "_id" : new \MongoId()
        ];
        let a = [
            "$set" : a
        ];
        let fields = null;
        let options = [
            "new" : true,
            "upsert" : true
        ];
        
        return this->_collection->findAndModify(query, a, fields, options);
    }

    /**
     * 删除指定范围的数据
     *
     * @param array criteria            
     * @param array options            
     */
    public function remove(array! criteria = NULL, array! options = NULL)
    {
        if criteria === NULL {
            throw new \Exception("criteria is NULL");
        }
        
        var defaultOptions = [];
        let defaultOptions = [
            "justOne" : self::JUSTONE,
            "fsync" : self::FSYNC
        ];
        
        let options = (options === NULL) ? defaultOptions : array_merge(defaultOptions, options);
        
        if isset options["justOne"] && !options["justOne"] {
            let options["multiple"] = true;
        }
        
        let criteria = this->appendQuery(criteria);
        return this->_collection->update(criteria, [
            "set" : [
                "__REMOVED__" : true
            ]
        ], options);
    }

    /**
     * 物理删除指定范围的数据
     *
     * @param array criteria            
     * @param array options            
     */
    public function physicalRemove(array! criteria = NULL, array options = NULL)
    {
        if criteria === NULL {
            throw new \Exception("criteria is NULL");
        }
        
        var defaultOptions = [];
        let defaultOptions = [
            "justOne" : self::JUSTONE,
            "fsync" : self::FSYNC
        ];
        
        let options = (options === NULL) ? defaultOptions : array_merge(defaultOptions, options);
        return this->_collection->remove(criteria, options);
    }

    /**
     * 物理更新数据
     *
     * @param array criteria            
     * @param array object            
     * @param array options            
     * @throws \Exception
     */
    public function physicalUpdate(criteria, obj, array options = NULL)
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
        
        let options = (options === NULL) ? defaultOptions : array_merge(defaultOptions, options);
        return this->_collection->update(criteria, obj, options);
    }

    /**
     * 更新指定范围的数据
     *
     * @param array criteria            
     * @param array object            
     * @param array options            
     */
    public function update(criteria, obj, array options = NULL)
    {
        if !is_array(criteria) {
            throw new \Exception("criteria is array");
        }
        
        if empty obj {
            throw new \Exception("object is empty");
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
        
        let options = (options === NULL) ? defaultOptions : array_merge(defaultOptions, options);
        
        let criteria = this->appendQuery(criteria);
        let obj = this->array_unset_recursive(obj, [
            "__CREATE_TIME__",
            "__MODIFY_TIME__",
            "__REMOVED__"
        ]);
        
        if (unlikely this->_collection->count(criteria) == 0) {
            if isset options["upsert"] && options["upsert"] {
                let criteria = this->addSharedKeyToQuery(criteria);
                this->_collection->update(criteria, [
                    "set" : [
                        "__CREATE_TIME__" : new \MongoDate(),
                        "__MODIFY_TIME__" : new \MongoDate(),
                        "__REMOVED__" : false
                    ]
                ], options);
            }
        } else {
            unset(options["upsert"]);
            this->_collection->update(criteria, [
                "set" : [
                    "__MODIFY_TIME__" : new \MongoDate()
                ]
            ], options);
        }
        
        return this->_collection->update(criteria, obj, options);
    }

    /**
     * 保存并保持引用修改状态
     *
     * @param array a            
     * @param array options            
     * @return mixed
     */
    public function save(array! a, array! options = NULL)
    {
        if !isset a["__CREATE_TIME__"] {
            let a["__CREATE_TIME__"] = new \MongoDate();
        }
        let a["__REMOVED__"] = false;
        let a["__MODIFY_TIME__"] = new \MongoDate();
        if (options == null) {
            let options = [
                "w" : 1
            ];
        }
        return this->_collection->save(a, options);
    }

    /**
     * 保存并保持引用修改状态
     *
     * @param array a            
     * @param array options            
     * @return mixed
     */
    public function saveRef(array! a, array options = NULL)
    {
        return this->save(a, options);
    }

    /**
     * 执行DB的command操作,直接运行命令行操作数据库中的数据，慎用
     *
     * @param array command            
     * @return array
     */
    public function command(array! command)
    {
        return this->_collection->db->command(command);
    }

    /**
     * mapreduce 错误评价
     *
     */
    private function failure(int! code, string! msg) {
        if is_array(msg) {
           let msg = json_encode(msg);
        }
        return [
            "ok" : 0,
            "code" : code,
            "msg" : msg
        ];
    }

    /**
     * 执行map reduce操作,为了防止数据量过大，导致无法完成mapreduce,统一采用集合的方式，取代内存方式
     * 内存方式，不允许执行过程的数据量量超过物理内存的10%，故无法进行大数量分析工作。
     *
     * @param array command            
     */
    public function mapReduce(string out = null, map, reduce, array! query = [], finalize = null, string! method = "replace", scope = null, sort = null, limit = null)
    {
        if (out == null) {
            var arrArgs;
            let arrArgs = func_get_args();
            let out = md5(serialize(arrArgs));
        }
    
        // map reduce执行锁管理结束
        var command,rst;
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
            var outMongoCollection;
            let outMongoCollection = new self(out, self::DB_MAPREDUCE, this->_clusterName);
            outMongoCollection->setMongoClient(this->_client);
            outMongoCollection->setNoAppendQuery(true);
            return outMongoCollection;
        } else {
            return this->failure(501, rst);
        }
    }

    /**
     * 云存储文件
     *
     * @param string fieldName
     *            上传表单字段的名称
     * @return array 返回上传文件成功后的object
     *        
     *         object结构如下:
     *         array(
     *         ["_id"] :
     *         MongoId(
     *        
     *         id =
     *         "537cc9b54896194b228b4581"
     *         )
     *         ["collection_id"] :
     *         NULL
     *         ["name"] :
     *         "b21c8701a18b87d624ac8e2d050828381f30fd11.jpg"
     *         ["type"] :
     *         "image/jpeg"
     *         ["tmp_name"] :
     *         "/tmp/phpeBS799"
     *         ["error"] :
     *         0
     *         ["size"] :
     *         350522
     *         ["mime"] :
     *         "image/jpeg; charset=binary"
     *         ["filename"] :
     *         "b21c8701a18b87d624ac8e2d050828381f30fd11.jpg"
     *         ["uploadDate"] :
     *         MongoDate(
     *        
     *         sec =
     *         1400687029
     *         usec =
     *         515000
     *         )
     *         ["length"] :
     *         350522
     *         ["chunkSize"] :
     *         262144
     *         ["md5"] :
     *         "3a736c4eed22030dde16df11fee263e7"
     *         )
     *        
     */
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
        let finfo = new \finfo(FILEINFO_MIME);
        let mime = finfo->file(_FILES[fieldName]["tmp_name"]);
        if mime !== false {
            let metadata["mime"] = mime;
        }
        
        this->initGridFS();
        let id = this->_fs->storeUpload(fieldName, metadata);
        let gridfsFile = this->_fs->get(id);
        if !(gridfsFile instanceof \MongoGridFSFile) {
            throw new \Exception("gridfsFile is not instanceof MongoGridFSFile");
        }
        
        return gridfsFile->file;
    }

    /**
     * 存储二进制内容
     *
     * @param bytes bytes            
     * @param string filename            
     * @param array metadata            
     */
    public function storeBytesToGridFS(bytes, string! filename = "", array! metadata = [])
    {
        var finfo,mime,id,gridfsFile;
        if !is_array(metadata) {
            let metadata = [];
        }
        
        if !empty filename {
            let metadata["filename"] = filename;
        }
        
        let finfo = new \finfo(FILEINFO_MIME);
        let mime = finfo->buffer(bytes);
        if mime !== false {
            let metadata["mime"] = mime;
        }

        this->initGridFS();
        let id = this->_fs->storeBytes(bytes, metadata);
        let gridfsFile = this->_fs->get(id);
        return gridfsFile->file;
    }

    /**
     * 获取指定ID的GridFSFile对象
     *
     * @param string id            
     * @return \MongoGridFSFile object
     */
    public function getGridFsFileById(id)
    {
        if !(id instanceof \MongoId) {
            let id = new \MongoId(id);
        }
        
        this->initGridFS();
        return this->_fs->get(id);
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
    public function getInfoFromGridFS(id)
    {
        var gridfsFile;
        if !(id instanceof \MongoId) {
            let id = new \MongoId(id);
        }
        this->initGridFS();
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
        var gridfsFile;
        if !(id instanceof \MongoId) {
            let id = new \MongoId(id);
        }
        this->initGridFS();
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
        return this->_fs->remove([
            "_id" : id
        ]);
    }


    private function array_unset_recursive(array! arr, array! fields, boolean remove = true)
    {
        var key,value;
        for key,value in arr {
            if remove {
                if in_array(key, fields, true) {
                    unset(arr[key]);
                } else {
                    if is_array(value) {
                        this->array_unset_recursive(value, fields, remove);
                    }
                }
            } else {
                if !in_array(key, fields, true) {
                    unset(arr[key]);
                } else {
                    if is_array(value) {
                        this->array_unset_recursive(value, fields, remove);
                    }
                }
            }
        }

        return arr;
    }


    /**
     * 打印最后一个错误信息
     */
    private function debug()
    {
        if this->_db instanceof \MongoDB {
            var err;
            let err = this->_db->lastError();
            // 在浏览器中输出错误信息以便发现问题
            return err;
        }
    }

    /**
     * 在析构函数中调用debug方法
     */
    public function __destruct()
    {}

}