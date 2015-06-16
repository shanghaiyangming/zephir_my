namespace My\Mongo\Plugin;

class Icc
{
	private _model;

	public function __construct(config, string! collection, string! database, string! cluster, array! collectionOptions = []) {
		var obj;
		let obj = new \My\Mongo\Collection(collection, database, collectionOptions);
		let obj->gridfs_prefix = "icc_";
		let this->_model = obj;
	}

	public function __call(string! method, arguments) {
		var rst;
        let rst = call_user_func_array([this->_model,method],arguments);
        return rst;
	}

	public function __destruct() {

	}
}