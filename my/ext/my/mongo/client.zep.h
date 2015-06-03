
extern zend_class_entry *my_mongo_client_ce;

ZEPHIR_INIT_CLASS(My_Mongo_Client);

PHP_METHOD(My_Mongo_Client, init);

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_client_init, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, servers, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(my_mongo_client_method_entry) {
	PHP_ME(My_Mongo_Client, init, arginfo_my_mongo_client_init, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
