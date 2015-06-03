namespace My\Utils;

class Lock
{
	static _cache = null;

    private _key = "";

    private _expire = 30;

    private _isInstance = false;

    private _isLocked = false;

    private _autoUnLock = true;

	public function __construct(string! key) -> void
	{
		let self::_cache = self::connect();
		let this->_key = key;
		let this->_expire = ini_get("max_execution_time");
	}

	public static function connect() -> <\Memcached>
	{
		if empty self::_cache {
			var servers;
			var config;
			var objMemcached;
			array memcachedConfig = [];

			let objMemcached = new \Memcached();

            if Registry::isRegistered("my_memcached_config") {
                let config = Registry::get("my_memcached_config");
            } else if isset _SERVER["MEMCACHED_SERVER"] {
				let config = _SERVER["MEMCACHED_SERVER"];
			} else {
				let config = "tcp://127.0.0.1:11211/?weight=20";
			}
			

			let servers = explode(";",config);
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
            throw new \Exception("每个Lock实例只能lock一次，当一个请求中需要多次锁定时，请分别实例化Lock类");
        }
        
        let this->_isInstance = true;
        var casToken,value,expireTime,now,n;
        let casToken = microtime(true);
        let n = 0;
        while n==0 || self::_cache->getResultCode() != \Memcached::RES_SUCCESS {
        	let value = self::_cache->get($this->_key, null, casToken);
        	if (self::_cache->getResultCode() == \Memcached::RES_NOTFOUND) {
        		let now = time();
                let expireTime = now + this->_expire;
                self::_cache->add(this->_key, expireTime, expireTime);
                let this->_isLocked = false;
            } else {
                self::_cache->cas(casToken, this->_key, value, value);
                let this->_isLocked = true;
            }
            let n++;
        }
        return this->_isLocked;
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