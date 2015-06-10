namespace My\Mongo;

class Client
{
	/**
	 * servers = array("127.0.0.1:57017","127.0.0.1:27017");
     * servers = "mongodb://127.0.0.1:27017"
	 */
	public static function init(dns = null) {
        if !class_exists("\MongoClient") {
            throw new \Exception("please install php_mongodb 1.4+");
        }
        if is_array(dns) {
    		if empty dns {
    			throw new \Exception("please setting mongodb server information");
    		}
            shuffle(dns);
            string dnsString = "";
            let dnsString = "mongodb://".join(",", dns);
        } elseif is_string(dns) {
            let dnsString = dns;
        } else {
            let dnsString = "mongodb://127.0.0.1:27017";
        }

        var options;
        let options = [];
        let options["connect"] = false;

        var connect;
        let connect = new \MongoClient(dnsString, options);
        string readPreference = "";
        let readPreference = \MongoClient::RP_PRIMARY_PREFERRED;
        if connect instanceof \MongoClient {
            connect->{"setReadPreference"}(readPreference); 
        }


        return connect;
	}
}