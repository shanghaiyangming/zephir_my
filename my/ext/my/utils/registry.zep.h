
extern zend_class_entry *my_utils_registry_ce;

ZEPHIR_INIT_CLASS(My_Utils_Registry);

PHP_METHOD(My_Utils_Registry, getInstance);
PHP_METHOD(My_Utils_Registry, setInstance);
PHP_METHOD(My_Utils_Registry, init);
PHP_METHOD(My_Utils_Registry, setClassName);
PHP_METHOD(My_Utils_Registry, _unsetInstance);
PHP_METHOD(My_Utils_Registry, get);
PHP_METHOD(My_Utils_Registry, set);
PHP_METHOD(My_Utils_Registry, isRegistered);
PHP_METHOD(My_Utils_Registry, __construct);
PHP_METHOD(My_Utils_Registry, offsetExists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_utils_registry_setinstance, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, registry, My\\Utils\\Registry, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_utils_registry_setclassname, 0, 0, 0)
	ZEND_ARG_INFO(0, registryClassName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_utils_registry_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_utils_registry_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_utils_registry_isregistered, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_utils_registry___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arr, 1)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_utils_registry_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(my_utils_registry_method_entry) {
	PHP_ME(My_Utils_Registry, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(My_Utils_Registry, setInstance, arginfo_my_utils_registry_setinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(My_Utils_Registry, init, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(My_Utils_Registry, setClassName, arginfo_my_utils_registry_setclassname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(My_Utils_Registry, _unsetInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(My_Utils_Registry, get, arginfo_my_utils_registry_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(My_Utils_Registry, set, arginfo_my_utils_registry_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(My_Utils_Registry, isRegistered, arginfo_my_utils_registry_isregistered, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(My_Utils_Registry, __construct, arginfo_my_utils_registry___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(My_Utils_Registry, offsetExists, arginfo_my_utils_registry_offsetexists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
