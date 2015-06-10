namespace My\Mongo\Plugin;

class Icc
{
	private _model;

	public function __construct(config, collection, database, cluster) {
		let this->_model = new \My\Mongo\Collection(collection, database);
		this->_model->gridfs_prefix = 'icc_';
	}

	public function __call(string! method, arguments) {
		var rst;
        let rst = call_user_func_array([this->_model,method],arguments);
        return rst;
	}

	public function __destruct() {

	}
}