
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/time.h"


ZEPHIR_INIT_CLASS(My_Utils_Lock) {

	ZEPHIR_REGISTER_CLASS(My\\Utils, Lock, my, utils_lock, my_utils_lock_method_entry, 0);

	zend_declare_property_null(my_utils_lock_ce, SL("_cache"), ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(my_utils_lock_ce, SL("_key"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(my_utils_lock_ce, SL("_expire"), 30, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(my_utils_lock_ce, SL("_isInstance"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(my_utils_lock_ce, SL("_isLocked"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(my_utils_lock_ce, SL("_autoUnLock"), 1, ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(My_Utils_Lock, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0 = NULL, _1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_SELF(&_0, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_update_static_property_ce(my_utils_lock_ce, SL("_cache"), &_0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_key"), key TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "max_execution_time", 0);
	ZEPHIR_CALL_FUNCTION(&_0, "ini_get", NULL, 24, &_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_expire"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Utils_Lock, connect) {

	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS, weight = 1;
	zval *memcachedConfig, *params, *_10 = NULL;
	zval *_0, *servers, *config = NULL, *objMemcached, *_SERVER, *server = NULL, **_3, *arr = NULL, *host = NULL, *port = NULL, *_5, *_7 = NULL, *_8, *_9, *_11 = NULL, *_12;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(memcachedConfig);
	array_init(memcachedConfig);
	ZEPHIR_INIT_VAR(params);
	array_init(params);

	_0 = zephir_fetch_static_property_ce(my_utils_lock_ce, SL("_cache") TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_INIT_VAR(objMemcached);
		object_init_ex(objMemcached, zephir_get_internal_ce(SS("memcached") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, objMemcached, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		if (zephir_array_isset_string(_SERVER, SS("MEMCACHED_SERVER"))) {
			zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
			ZEPHIR_OBS_VAR(config);
			zephir_array_fetch_string(&config, _SERVER, SL("MEMCACHED_SERVER"), PH_NOISY, "my/utils/lock.zep", 34 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(config);
			ZVAL_STRING(config, "tcp://127.0.0.1:11211/?weight=20", 1);
		}
		ZEPHIR_INIT_VAR(servers);
		zephir_fast_explode_str(servers, SL(";"), config, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(servers, &_2, &_1, 0, 0, "my/utils/lock.zep", 57);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(server, _3);
			ZEPHIR_CALL_FUNCTION(&arr, "parse_url", &_4, 25, server);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(host);
			zephir_array_fetch_string(&host, arr, SL("host"), PH_NOISY, "my/utils/lock.zep", 45 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(port);
			zephir_array_fetch_string(&port, arr, SL("port"), PH_NOISY, "my/utils/lock.zep", 46 TSRMLS_CC);
			zephir_array_fetch_string(&_5, arr, SL("query"), PH_NOISY | PH_READONLY, "my/utils/lock.zep", 49 TSRMLS_CC);
			Z_SET_ISREF_P(params);
			ZEPHIR_CALL_FUNCTION(NULL, "parse_str", &_6, 26, _5, params);
			Z_UNSET_ISREF_P(params);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_7);
			zephir_array_fetch_string(&_8, params, SL("weight"), PH_NOISY | PH_READONLY, "my/utils/lock.zep", 50 TSRMLS_CC);
			if (ZEPHIR_IS_EMPTY(_8)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 1);
			} else {
				zephir_array_fetch_string(&_9, params, SL("weight"), PH_NOISY | PH_READONLY, "my/utils/lock.zep", 50 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, zephir_get_intval(_9));
			}
			weight = zephir_get_numberval(_7);
			ZEPHIR_INIT_NVAR(_10);
			zephir_create_array(_10, 3, 0 TSRMLS_CC);
			zephir_array_update_string(&_10, SL("host"), &host, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10, SL("port"), &port, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_LONG(_11, weight);
			zephir_array_update_string(&_10, SL("weight"), &_11, PH_COPY | PH_SEPARATE);
			zephir_array_append(&memcachedConfig, _10, PH_SEPARATE, "my/utils/lock.zep", 55);
		}
		ZEPHIR_CALL_METHOD(NULL, objMemcached, "addservers", NULL, 0, memcachedConfig);
		zephir_check_call_status();
		zephir_update_static_property_ce(my_utils_lock_ce, SL("_cache"), &objMemcached TSRMLS_CC);
		RETURN_CCTOR(objMemcached);
	}
	_12 = zephir_fetch_static_property_ce(my_utils_lock_ce, SL("_cache") TSRMLS_CC);
	RETURN_CTOR(_12);

}

/**
 * 设定缓存的强制锁定时间,必须锁定足够时间才能解锁
 *
 * @param number sec            
 */
PHP_METHOD(My_Utils_Lock, setExpire) {

	zval *sec_param = NULL, *_0;
	int sec;

	zephir_fetch_params(0, 0, 1, &sec_param);

	if (!sec_param) {
		sec = 5;
	} else {
	if (unlikely(Z_TYPE_P(sec_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sec' must be a long/integer") TSRMLS_CC);
		RETURN_NULL();
	}

	sec = Z_LVAL_P(sec_param);
	}


	zephir_update_property_this(this_ptr, SL("_autoUnLock"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, sec);
	zephir_update_property_this(this_ptr, SL("_expire"), _0 TSRMLS_CC);

}

/**
 * 采用CAS乐观锁
 *
 * @throws Exception
 * @return boolean
 */
PHP_METHOD(My_Utils_Lock, lock) {

	zend_bool _1;
	int n, ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *casToken, *value = NULL, *expireTime = NULL, *now = NULL, *_2, *_3 = NULL, *_4, *_5, *_6 = NULL, *_7, *_8 = NULL, *_9, *_10;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_isInstance"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "每个Lock实例只能lock一次，当一个请求中需要多次锁定时，请分别实例化Lock类", "my/utils/lock.zep", 86);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_isInstance"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_VAR(casToken);
	zephir_microtime(casToken, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	n = 0;
	while (1) {
		_1 = n == 0;
		if (!(_1)) {
			_2 = zephir_fetch_static_property_ce(my_utils_lock_ce, SL("_cache") TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3, _2, "getresultcode", NULL, 0);
			zephir_check_call_status();
			_1 = !ZEPHIR_IS_LONG(_3, 0);
		}
		if (!(_1)) {
			break;
		}
		_4 = zephir_fetch_static_property_ce(my_utils_lock_ce, SL("_cache") TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_NULL(_6);
		ZEPHIR_CALL_METHOD(&value, _4, "get", NULL, 0, _5, _6, casToken);
		zephir_check_call_status();
		_7 = zephir_fetch_static_property_ce(my_utils_lock_ce, SL("_cache") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_8, _7, "getresultcode", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(_8, 16)) {
			ZEPHIR_INIT_NVAR(now);
			zephir_time(now);
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_expire"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(expireTime);
			zephir_add_function_ex(expireTime, now, _9 TSRMLS_CC);
			_9 = zephir_fetch_static_property_ce(my_utils_lock_ce, SL("_cache") TSRMLS_CC);
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _9, "add", NULL, 0, _10, expireTime, expireTime);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_isLocked"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		} else {
			_9 = zephir_fetch_static_property_ce(my_utils_lock_ce, SL("_cache") TSRMLS_CC);
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _9, "cas", NULL, 0, casToken, _10, value, value);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_isLocked"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		n++;
	}
	RETURN_MM_MEMBER(this_ptr, "_isLocked");

}

PHP_METHOD(My_Utils_Lock, release) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(my_utils_lock_ce, SL("_cache") TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "delete", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(My_Utils_Lock, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1;
	zval *_0, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_isLocked"), PH_NOISY_CC);
	_1 = !zephir_is_true(_0);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_autoUnLock"), PH_NOISY_CC);
		_1 = zephir_is_true(_2);
	}
	if (_1) {
		_3 = zephir_fetch_static_property_ce(my_utils_lock_ce, SL("_cache") TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _3, "delete", NULL, 0, _4);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_isInstance"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

