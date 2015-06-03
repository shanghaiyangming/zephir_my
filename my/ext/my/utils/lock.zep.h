
extern zend_class_entry *my_utils_lock_ce;

ZEPHIR_INIT_CLASS(My_Utils_Lock);

PHP_METHOD(My_Utils_Lock, __construct);
PHP_METHOD(My_Utils_Lock, connect);
PHP_METHOD(My_Utils_Lock, setExpire);
PHP_METHOD(My_Utils_Lock, lock);
PHP_METHOD(My_Utils_Lock, release);
PHP_METHOD(My_Utils_Lock, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_utils_lock___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_utils_lock_setexpire, 0, 0, 0)
	ZEND_ARG_INFO(0, sec)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(my_utils_lock_method_entry) {
	PHP_ME(My_Utils_Lock, __construct, arginfo_my_utils_lock___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(My_Utils_Lock, connect, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(My_Utils_Lock, setExpire, arginfo_my_utils_lock_setexpire, ZEND_ACC_PUBLIC)
	PHP_ME(My_Utils_Lock, lock, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Utils_Lock, release, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Utils_Lock, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
