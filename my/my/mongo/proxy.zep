namespace My\Mongo;

class Proxy
{
	private _model = null;

	private _cacheOpList = ["findOne","findAll"];

	private _clearOpList = ["save","remove","update"];

	public function __construct() {

	}

	public function __call(string! method, arguments) {
		var rst;
        let rst = call_user_func_array([this->_model,method],arguments);
        return rst;
	}

	public function __destruct() {

	}
}