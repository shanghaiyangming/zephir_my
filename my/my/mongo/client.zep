namespace My\Mongo;

class Client
{
	/**
	 * servers = array("127.0.0.1:57017","127.0.0.1:27017");
	 */
	public static function init(array! servers) {
		if empty servers {
			throw new \Exception("please setting mongodb server information");
		}

        shuffle(servers);
        var options;
        let options = [];
        let options["connect"] = false;

        string dnsString = "";
        let dnsString =  (string) join(",", servers);
        var connect;
        if class_exists("\MongoClient") {
            let connect = new \MongoClient("mongodb://".dnsString, options);
            string readPreference = "";
            let readPreference = \MongoClient::RP_PRIMARY_PREFERRED;
            if connect instanceof \MongoClient {
                connect->{"setReadPreference"}(readPreference); 
            }
        } else {
            throw new \Exception("please install php_mongodb 1.4+");
        }

        return connect;
	}
}