namespace My\Mongo\Plugin;

class Iwebsite
{
	private _project_id = null;

	private _collection_id = null;

	private _fileField = [];

	private _key = null;

	private _collection = null;

	private _mapping = null;

	private _structure = null;

	private _cache;

	private _model;

	const DOMAIN = "http://cloud.umaman.com";

	const EXPIRE = 600;

	const DATABASE = "ICCv1";

	const IDATABASE_KEYS = "idatabase_keys";

	const IDATABASE_COLLECTIONS = "idatabase_collections";

	const IDATABASE_MAPPING = "idatabase_mapping";

	const IDATABASE_STRUCTURES = "idatabase_structures";

	const READ_PERFERENCE = "secondaryPreferred";

    public function __construct()
    {
        let this->_key = new \My\Mongo\Collection(self::IDATABASE_KEYS, self::DATABASE);
        this->_key->setReadPreference(self::READ_PERFERENCE);
        let this->_collection = new \My\Mongo\Collection(self::IDATABASE_COLLECTIONS, self::DATABASE);
        this->_collection->setReadPreference(self::READ_PERFERENCE);
        let this->_mapping = new \My\Mongo\Collection(self::IDATABASE_MAPPING, self::DATABASE);
        this->_mapping->setReadPreference(self::READ_PERFERENCE);
        let this->_structure = new \My\Mongo\Collection(self::IDATABASE_STRUCTURES, self::DATABASE);
        this->_structure->setReadPreference(self::READ_PERFERENCE);
        let this->_cache = new \My\Utils\Cache();
	}

	public function authenticate(string! project_id, string! rand, string! sign, string! key_id = null) -> boolean
    {
        if strlen(rand) < 8 {
            throw new \Exception("rand length must be more than 8");
        }
        let this->_project_id = project_id;
        let key_id = !empty key_id ? key_id : null;
        var keyInfo;
        let keyInfo = this->getKeysInfo(project_id, key_id);
        if md5(project_id . rand . keyInfo["key"]) !== strtolower(sign) {
            throw new \Exception("authenticate failed");
        }
        return true;
    }

    private function getKeysInfo(string! project_id, string! key_id = null)
    {
    	var cacheKey;
        let cacheKey = md5("getKeysInfo" . this->_project_id . key_id);
        var rst;
        let rst = this->_cache->load(cacheKey);
        if rst === false {
	    	var query;
	        let query = [];
	        let query["project_id"] = project_id;
	        if !empty key_id {
	        	let query["_id"] = new \MongoId(key_id);
	        } else {
	            let query["default"] = true;
	        }
	        let query["expire"] = [
	            "$gte" : new \MongoDate()
	        ];
	        let query["active"] = true;

	        let rst = this->_key->findOne(query, [
	            "key" : true
	        ]);
	        if empty rst {
	            throw new \Exception("authenticate invalid");
	        }
	        this->_cache->save(rst, cacheKey, self::EXPIRE);
	    } 

	    return rst;
    }

    public function setCollection(string! collectionAlias = null) -> void
    {
    	var cacheKey,rst,mapping;
        let cacheKey = md5("setCollection".this->_project_id.collectionAlias);
        let rst = this->_cache->load(cacheKey);
        
        if rst === false {
	    	var collectionInfo;
	        let collectionInfo = this->_collection->findOne([
	            "project_id" : this->_project_id,
	            "alias" : collectionAlias
	        ]);
	        if empty collectionInfo {
	            throw new \Exception(collectionAlias . " not existed");
	        }
	        
	        let this->_collection_id = collectionInfo["_id"]->__toString();
	        let mapping = this->_mapping->findOne([
	            "project_id" : this->_project_id,
	            "collection_id" : this->_collection_id,
	            "active" : true
	        ]);

            let rst = [];
            let rst["collection_id"] = this->_collection_id;
            let rst["mapping"] = mapping;
            this->_cache->save(rst, cacheKey, self::EXPIRE);
	    } else {
	    	let this->_collection_id = rst["collection_id"];
	    	let mapping = rst["mapping"];
	    }

        var obj;
        if empty mapping {
            let obj = new \My\Mongo\Collection(this->iCollectionName(this->_collection_id), self::DATABASE);
        } else {
            let obj = new \My\Mongo\Collection(mapping["collection"], mapping["database"]);
        }
        let obj->gridfs_prefix = "icc_";
        let this->_model = obj;
        this->getSchema();
    }

    public function setReadFromSecondary(boolean! flag = false) -> void
    {
        this->_model->setReadPreference(flag == true ? "secondaryPreferred" : "primaryPreferred");
    }

    public function getSchema() -> void
    {
        if empty this->_collection_id {
            throw new \Exception("_collection_id not existed");
        }
        
        if empty this->_project_id {
            throw new \Exception("_project_id not existed");
        }
        
        var cacheKey;
        let cacheKey = md5("getSchema" . this->_project_id . this->_collection_id);
        var rst;
        let rst = this->_cache->load(cacheKey);
        if rst === false {
        	var cursor;
            let cursor = this->_structure->find([
                "collection_id" : this->_collection_id
            ]);
            
            if unlikely cursor->count() == 0 {
                throw new \Exception("structure no setting");
            }
            
            while cursor->hasNext() {
            	var row;
                let row = cursor->getNext();
                var type = "";
                if fetch type, row["type"] {
                	if type === "filefield" {
                    	let this->_fileField[row["field"]] = row;
                	}
                }
            }

            let rst = [];
            let rst["fileField"] = this->_fileField;
            this->_cache->save(rst, cacheKey, self::EXPIRE);
        } else {
            let this->_fileField = !empty rst["fileField"] ? rst["fileField"] : [];
        }
    }

    private function toArray(arr)
    {
    	var key,value;
        for key,value in arr {
            if key === "_id" && strlen(value) === 24 {
                if !(value instanceof \MongoId) {
                	let arr[key] = new \MongoId(value);
                }       
            } elseif is_array(value) {
                let arr[key] = this->toArray(value);
            }
        }
        return arr;
    }

    private function result(arr)
    {
        if (! empty(this->_fileField) && is_array(arr)) {
        	var key,value;
	        for key,value in arr {
	        	if is_array(value) {
	                let arr[key] = this->result(value);
	            }
	            if in_array(key, array_keys(this->_fileField), true) {
                    if !empty value {
                        if empty this->_fileField[key]["displayFileId"] {
                            let arr[key] = empty this->_fileField[key]["cdnUrl"] ? self::DOMAIN : this->_fileField[key]["cdnUrl"] . "/file/" . value;
                        }
                    }
                }
	        }
        }
        return arr;
    }

    private function iCollectionName(_id) -> string
    {
    	var _id_string;
    	let _id_string = _id instanceof \MongoId ? _id->__toString() : _id;
        return "idatabase_collection_" . _id_string;
    }

    public function find(array! query = [], array! sort, int skip = 0, int limit = 20, array! fields = [])
    {
        let query = this->toArray(query);
        let sort = this->toArray(sort);
        let skip = intval(skip);
        let skip = skip > 0 ? skip : 0;
        let limit = intval(limit);
        let limit = limit < 0 ? 10 : limit;
        let limit = limit > 1000 ? 1000 : limit;
        if !empty fields {
            let fields = this->toArray(fields);
        } else {
            let fields = [];
        }
        
        var cursor,total;
        let cursor = this->_model->find(query, fields);
        let total = cursor->count();
        if !empty sort {
            cursor->sort(sort);
        }
        if skip > 0 {
            cursor->skip(skip);
        }
        cursor->limit(limit);
        
        var rst;
        let rst = [];
        let rst["datas"] = iterator_to_array(cursor, false);
        let rst["total"] = total;
        return this->result(rst);
    }

    public function uploadFile(fileBytes, string! fileName)
    {
        if (base64_encode(base64_decode(fileBytes, true)) === fileBytes) {
            let fileBytes = base64_decode(fileBytes);
        }
        
        var rst;
        let rst = this->_model->storeBytesToGridFS(fileBytes, fileName, [
            "collection_id" : this->_collection_id,
            "project_id" : this->_project_id
        ]);
        return this->result(rst);
    }

	public function __call(string! method, arguments) {
		var newArgument;
		let newArgument = [];
		if is_array(arguments) {
			var argument;
			for argument in arguments {
				let newArgument[] = this->toArray(argument);
			}
        }

		var rst;
        let rst = call_user_func_array([this->_model,method],newArgument);
        return this->result(rst);
	}

}