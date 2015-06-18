namespace My\Mongo\Plugin\Proxy;

class Iwebsite
{
	private _model = null;

	private _cache = null;

	private _queryCache = false;

	private _cachePrefix = "my_mongo_iwebsite_query_cache_";

	private _cacheOpList = ["find","findOne","findAll"];

	private _clearOpList = ["findAndModify","findAndModifyByCommand","save","saveRef","remove","physicalRemove","update","physicalUpdate","insert","insertRef","insertByFindAndModify","batchInsert","drop","physicalDrop"];

	private _cacheContainer = null;

	const EXPIRE = 60;

	public function __construct() {
		let this->_cache = new \My\Utils\Cache();
		let this->_model = new \My\Mongo\Plugin\Iwebsite();
	}

	public function setCollection(string! collectionAlias = null) -> boolean
    {
    	let this->_cacheContainer = this->_cachePrefix . this->_model->_project_id . collectionAlias;
        return this->_model->setCollection(collectionAlias);
    }

	public function setQueryCache(boolean flag = false) -> void
	{
		let this->_queryCache = flag;
	}

	public function setCacheOpList(array! arr) -> void
	{
		let this->_cacheOpList = arr;
	}

	public function __call(string! method, arguments) {
		var rst;
		if this->_queryCache {
			var cacheKey;
			let cacheKey = md5(method . serialize(arguments));
			if in_array(method, this->_clearOpList, true) {
				var clearItemList;
				let clearItemList = this->_cache->load(this->_cacheContainer);
				if clearItemList !== false && is_array(clearItemList) {
					this->_cache->removeAll(clearItemList);
				}
			} elseif in_array(method, this->_cacheOpList, true) {
				var cacheResult;
				let cacheResult = this->_cache->load(cacheKey);
				if cacheResult===false {
			        let rst = call_user_func_array([this->_model,method],arguments);
			        if unlikely this->_cache->save(rst, cacheKey, self::EXPIRE) == true {
			        	this->_cache->pushItemCas(this->_cacheContainer,cacheKey);
			        }
			        return rst;
			    } else {
			    	return cacheResult;
			    }
			}
		}
        let rst = call_user_func_array([this->_model,method],arguments);
        return rst;
	}

	public function __destruct() {
		if rand(0,1000)===999 {
			var cacheList;
			let cacheList = this->_cache->load(this->_cacheContainer);
			if cacheList!==false && is_array(cacheList) {
				if count(cacheList) > 10000 {
					this->_cache->removeAll(cacheList);
				}
			}
		}
	}
}