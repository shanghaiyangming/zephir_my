namespace My\Utils;

class Registry extends \ArrayObject
{

    private static _registryClassName = "\My\Utils\Registry";

    private static _registry = null;


    public static function getInstance()
    {
        if self::_registry === null {
            self::init();
        }

        return self::_registry;
    }

    public static function setInstance(<Registry> registry)
    {
        if self::_registry !== null {
            throw new \Exception("Registry is already initialized");
        }

        self::setClassName(get_class(registry));
        let self::_registry = registry;
    }

    protected static function init()
    {
    	var className;
    	let className = self::_registryClassName;
        self::setInstance(new {className}());
    }

    public static function setClassName(string! registryClassName = "\My\Utils\Registry")
    {
        if self::_registry !== null {
            throw new \Exception("Registry is already initialized");
        }

        if (!is_string(registryClassName)) {
            throw new \Exception("Argument is not a class name");
        }

        let self::_registryClassName = registryClassName;
    }

    public static function _unsetInstance()
    {
        let self::_registry = null;
    }

    public static function get(string! index)
    {
    	var instance;
        let instance = self::getInstance();
        if !instance->offsetExists(index) {
            throw new \Exception("No entry is registered for key 'index'");
        }

        return instance->offsetGet(index);
    }

    public static function set(string! index, value)
    {
    	var instance;
        let instance = self::getInstance();
        instance->offsetSet(index, value);
    }

    public static function isRegistered(string! index)
    {
        if self::_registry === null {
            return false;
        }
        return self::_registry->offsetExists(index);
    }

    public function __construct(array! arr = [], flags = parent::ARRAY_AS_PROPS)
    {
        parent::__construct(arr, flags);
    }

    public function offsetExists(string! index)
    {
        return array_key_exists(index, this);
    }

}
