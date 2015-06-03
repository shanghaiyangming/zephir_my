namespace My\Mongo;

class Client
{
	/**
	 * servers = array("127.0.0.1:57017","127.0.0.1:27017");
	 */
	public static function init(array! servers,array! options = null) {
		if empty servers {
			throw new \Exception("请设定正确的服务器地址");
		}

        let servers = shuffle(servers);
        let options = [];
        string dnsString = "";
        let dnsString =  (string) join(",", servers);

        var connect;
        if class_exists("\MongoClient") {
            let connect = new \MongoClient("mongodb://".dnsString, options);
            string readPreference = "";
            let readPreference = \MongoClient::RP_PRIMARY_PREFERRED;
            if connect instanceof \MongoClient {
                //	connect->setReadPreference(readPreference); 
                connect->{"setReadPreference"}(readPreference); 
            }
        } else {
            throw new \Exception("请安装PHP的Mongo1.4+版本的扩展");
        }

        return connect;
	}
}