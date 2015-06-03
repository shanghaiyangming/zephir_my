
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
#include "ext/spl/spl_array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(My_Utils_Registry) {

	ZEPHIR_REGISTER_CLASS_EX(My\\Utils, Registry, my, utils_registry, spl_ce_ArrayObject, my_utils_registry_method_entry, 0);

	zend_declare_property_string(my_utils_registry_ce, SL("_registryClassName"), "\\My\\Utils\\Registry", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(my_utils_registry_ce, SL("_registry"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(My_Utils_Registry, getInstance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(my_utils_registry_ce, SL("_registry") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_CALL_SELF(NULL, "init", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_static_property_ce(my_utils_registry_ce, SL("_registry") TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(My_Utils_Registry, setInstance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *registry, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &registry);



	_0 = zephir_fetch_static_property_ce(my_utils_registry_ce, SL("_registry") TSRMLS_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Registry is already initialized", "my/utils/registry.zep", 23);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, registry, 0 TSRMLS_CC);
	ZEPHIR_CALL_SELF(NULL, "setclassname", NULL, 0, _1);
	zephir_check_call_status();
	zephir_update_static_property_ce(my_utils_registry_ce, SL("_registry"), &registry TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Utils_Registry, init) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_2;
	zval *className, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(className);
	zephir_read_static_property_ce(&className, my_utils_registry_ce, SL("_registryClassName") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_fetch_safe_class(_1, className);
	_2 = zend_fetch_class(Z_STRVAL_P(_1), Z_STRLEN_P(_1), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _2);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_SELF(NULL, "setinstance", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Utils_Registry, setClassName) {

	zval *registryClassName_param = NULL, *_0;
	zval *registryClassName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &registryClassName_param);

	if (!registryClassName_param) {
		ZEPHIR_INIT_VAR(registryClassName);
		ZVAL_STRING(registryClassName, "\\My\\Utils\\Registry", 1);
	} else {
	if (unlikely(Z_TYPE_P(registryClassName_param) != IS_STRING && Z_TYPE_P(registryClassName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'registryClassName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(registryClassName_param) == IS_STRING)) {
		zephir_get_strval(registryClassName, registryClassName_param);
	} else {
		ZEPHIR_INIT_VAR(registryClassName);
		ZVAL_EMPTY_STRING(registryClassName);
	}
	}


	_0 = zephir_fetch_static_property_ce(my_utils_registry_ce, SL("_registry") TSRMLS_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Registry is already initialized", "my/utils/registry.zep", 40);
		return;
	}
	if (!(Z_TYPE_P(registryClassName) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Argument is not a class name", "my/utils/registry.zep", 44);
		return;
	}
	zephir_update_static_property_ce(my_utils_registry_ce, SL("_registryClassName"), &registryClassName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Utils_Registry, _unsetInstance) {


	zephir_update_static_property_ce(my_utils_registry_ce, SL("_registry"), &(ZEPHIR_GLOBAL(global_null)) TSRMLS_CC);

}

PHP_METHOD(My_Utils_Registry, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *instance = NULL, *_0 = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	ZEPHIR_CALL_SELF(&instance, "getinstance", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, instance, "offsetexists", NULL, 0, index);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "No entry is registered for key 'index'", "my/utils/registry.zep", 60);
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(instance, "offsetget", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(My_Utils_Registry, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *value, *instance = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index_param, &value);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	ZEPHIR_CALL_SELF(&instance, "getinstance", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, instance, "offsetset", NULL, 0, index, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Utils_Registry, isRegistered) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *_0, *_1;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	_0 = zephir_fetch_static_property_ce(my_utils_registry_ce, SL("_registry") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_static_property_ce(my_utils_registry_ce, SL("_registry") TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "offsetexists", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(My_Utils_Registry, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arr_param = NULL, *flags = NULL;
	zval *arr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &arr_param, &flags);

	if (!arr_param) {
		ZEPHIR_INIT_VAR(arr);
		array_init(arr);
	} else {
	arr = arr_param;

	}
	if (!flags) {
		ZEPHIR_INIT_VAR(flags);
		ZVAL_LONG(flags, 2);
	}


	ZEPHIR_CALL_PARENT(NULL, my_utils_registry_ce, this_ptr, "__construct", NULL, 0, arr, flags);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Utils_Registry, offsetExists) {

	zval *index_param = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	RETURN_MM_BOOL(zephir_array_key_exists(this_ptr, index TSRMLS_CC));

}

