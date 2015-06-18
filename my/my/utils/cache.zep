namespace My\Utils;

class Cache
{
	static _cache = null;

	private _key = null;

    private static _config;

	public function __construct() -> void
	{
        self::checkConfig();
		let self::_cache = self::connect();
	}

    private static function checkConfig() {
        var config;
        if unlikely Registry::isRegistered("my_memcached_config") == true {
            let config = Registry::get("my_memcached_config");
        } else {
            let config = "tcp://127.0.0.1:11211/?weight=20";
        }
        if self::_config != config {
            let self::_cache = null;
        }
        let self::_config = config;
    }

	private static function connect() -> <\Memcached>
	{
		if empty self::_cache {
			var servers;
			var objMemcached;
			array memcachedConfig = [];

			let objMemcached = new \Memcached();
			let servers = explode(";",self::_config);
			var server;
			for server in servers {
				var arr,host,port;
				let arr = parse_url(server);
				let host = arr["host"];
				let port = arr["port"];
				int weight = 1;
				array params = [];
				parse_str(arr["query"],params);
				let weight = empty params["weight"] ? 1 : intval(params["weight"]);
				let memcachedConfig[] = [
					"host":host,
					"port":port,
					"weight":weight
				];
			}
			objMemcached->addServers(memcachedConfig);
			let self::_cache = objMemcached;
			return objMemcached;
		} 

		return self::_cache;
	}

	public function load(string! key) 
	{
		let this->_key = key;
		return self::_cache->get(key);
	}

	public function save(value, string! key = "", int! expire = 0) -> boolean
	{
		if empty key {
			if empty this->_key {
				throw new \Exception("please set cache key");
			} 
			return self::_cache->set(this->_key, value, expire);
		}
		return self::_cache->set(key, value, expire);
	}

	public function pushItemCas(string! key, value) -> boolean
	{
		var casToken,cacheValue;
        let casToken = microtime(true);
        do {
        	let cacheValue = self::_cache->get(key, null, casToken);
        	if is_array(cacheValue) {
	        	if in_array(value,cacheValue,true) {
	        		break;
	        	}
	        }
        	if self::_cache->getResultCode() == \Memcached::RES_NOTFOUND {
        		let cacheValue = [];
        		let cacheValue[] = value;
                self::_cache->add(key, cacheValue);
            } else {
            	let cacheValue[] = value;
                self::_cache->cas(casToken, key, cacheValue);
            }
        }  while self::_cache->getResultCode() != \Memcached::RES_SUCCESS;
        return true;
	}

	public function remove(string! key) -> boolean
	{
		return self::_cache->delete(key);
	}

	public function removeAll(array arr) ->boolean 
	{
		return self::_cache->deleteMulti(arr);
	}

}