namespace My\Utils;

class Lock
{
	static _cache = null;

    private _key = "";

    private _expire = 30;

    private _isInstance = false;

    private _isLocked = false;

    private _autoUnLock = true;

    private static _config;

	public function __construct(string! key) -> void
	{
        self::checkConfig();
		let self::_cache = self::connect();
		let this->_key = key;
		let this->_expire = ini_get("max_execution_time");
	}

    private static function checkConfig() {
        var config;
        if Registry::isRegistered("my_memcached_config") {
            let config = Registry::get("my_memcached_config");
        } elseif isset _SERVER["MEMCACHED_SERVER"] {
            let config = _SERVER["MEMCACHED_SERVER"];
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

	/**
     * 设定缓存的强制锁定时间,必须锁定足够时间才能解锁
     *
     * @param number sec            
     */
    public function setExpire(int! sec = 5) -> void
    {
        let this->_autoUnLock = false;
        let this->_expire = sec;
    }


    /**
     * 采用CAS乐观锁
     *
     * @throws Exception
     * @return boolean
     */
    public function lock() -> boolean
    {
        if this->_isInstance {
            throw new \Exception("Each object can be instantiated only once");
        }
        
        let this->_isInstance = true;
        var casToken,value,expireTime,now;
        let casToken = microtime(true);
        let now = time();
        let expireTime = now + this->_expire;
        do {
        	let value = self::_cache->get($this->_key, null, casToken);
        	if (self::_cache->getResultCode() == \Memcached::RES_NOTFOUND) {
                self::_cache->add(this->_key, expireTime, expireTime);
                let this->_isLocked = false;
            } else {
                if now > value {
                    self::_cache->delete(this->_key);
                    self::_cache->add(this->_key, expireTime, expireTime);
                    let this->_isLocked = false;
                } else {
                    self::_cache->cas(casToken, this->_key, value);
                    let this->_isLocked = true;
                }
            }
        }  while self::_cache->getResultCode() != \Memcached::RES_SUCCESS;
        return this->_isLocked;
    }

    public function getValue() {
        return self::_cache->get(this->_key);
    }

    public function release()
    {
        return self::_cache->delete(this->_key);
    }

    public function __destruct() -> void
    {
        if !this->_isLocked && this->_autoUnLock {
        	self::_cache->delete(this->_key);
        } 

        let this->_isInstance = false;
    }
}