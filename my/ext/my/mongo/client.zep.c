
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(My_Mongo_Client) {

	ZEPHIR_REGISTER_CLASS(My\\Mongo, Client, my, mongo_client, my_mongo_client_method_entry, 0);

	return SUCCESS;

}

/**
 * servers = array("127.0.0.1:57017","127.0.0.1:27017");
 */
PHP_METHOD(My_Mongo_Client, init) {

	zval *dnsString = NULL, *_2 = NULL, *_4, *readPreference = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *servers_param = NULL, *options_param = NULL, *_0 = NULL, *_1, *connect, _3;
	zval *servers = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &servers_param, &options_param);

	servers = servers_param;

	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
	options = options_param;

	}
	ZEPHIR_INIT_VAR(dnsString);
	ZVAL_STRING(dnsString, "", 1);
	ZEPHIR_INIT_VAR(readPreference);
	ZVAL_STRING(readPreference, "", 1);


	if (ZEPHIR_IS_EMPTY(servers)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "请设定正确的服务器地址", "my/mongo/client.zep", 10);
		return;
	}
	Z_SET_ISREF_P(servers);
	ZEPHIR_CALL_FUNCTION(&_0, "shuffle", NULL, 1, servers);
	Z_UNSET_ISREF_P(servers);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(servers, _0);
	ZEPHIR_INIT_NVAR(options);
	array_init(options);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_join_str(_1, SL(","), servers TSRMLS_CC);
	zephir_get_strval(_2, _1);
	ZEPHIR_CPY_WRT(dnsString, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "\\MongoClient", 0);
	if (zephir_class_exists(&_3, 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(connect);
		object_init_ex(connect, zephir_get_internal_ce(SS("mongoclient") TSRMLS_CC));
		if (zephir_has_constructor(connect TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_SV(_4, "mongodb://", dnsString);
			ZEPHIR_CALL_METHOD(NULL, connect, "__construct", NULL, 0, _4, options);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(readPreference);
		ZVAL_STRING(readPreference, "primaryPreferred", 1);
		if (zephir_instance_of_ev(connect, zephir_get_internal_ce(SS("mongoclient") TSRMLS_CC) TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, connect, "setreadpreference", NULL, 0, readPreference);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "请安装PHP的Mongo1.4+版本的扩展", "my/mongo/client.zep", 28);
		return;
	}
	RETURN_CCTOR(connect);

}

