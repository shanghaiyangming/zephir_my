
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(My_Mongo_Collection) {

	ZEPHIR_REGISTER_CLASS(My\\Mongo, Collection, my, mongo_collection, my_mongo_collection_method_entry, 0);

	zend_declare_property_null(my_mongo_collection_ce, SL("_client"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(my_mongo_collection_ce, SL("_collection"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(my_mongo_collection_ce, SL("_collectionName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(my_mongo_collection_ce, SL("_databaseName"), "ICCv1", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(my_mongo_collection_ce, SL("_clusterName"), "defaultOptions", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(my_mongo_collection_ce, SL("_collectionOptions"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(my_mongo_collection_ce, SL("_db"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(my_mongo_collection_ce, SL("_admin"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(my_mongo_collection_ce, SL("_backup"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(my_mongo_collection_ce, SL("_mapreduce"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(my_mongo_collection_ce, SL("_fs"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(my_mongo_collection_ce, SL("_queryHaystack"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(my_mongo_collection_ce, SL("_updateHaystack"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(my_mongo_collection_ce, SL("_noAppendQuery"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_long(my_mongo_collection_ce, SL("TIMEOUT"), 6000000 TSRMLS_CC);

	zend_declare_class_constant_bool(my_mongo_collection_ce, SL("FSYNC"), 0 TSRMLS_CC);

	zend_declare_class_constant_bool(my_mongo_collection_ce, SL("UPSERT"), 0 TSRMLS_CC);

	zend_declare_class_constant_bool(my_mongo_collection_ce, SL("MULTIPLE"), 1 TSRMLS_CC);

	zend_declare_class_constant_bool(my_mongo_collection_ce, SL("JUSTONE"), 0 TSRMLS_CC);

	zend_declare_class_constant_bool(my_mongo_collection_ce, SL("DEBUG"), 0 TSRMLS_CC);

	zend_declare_class_constant_string(my_mongo_collection_ce, SL("GRIDFS_PREFIX"), "icc_" TSRMLS_CC);

	zend_declare_class_constant_string(my_mongo_collection_ce, SL("DB_MAPREDUCE"), "mapreduce" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(My_Mongo_Collection, setCollection) {

	zval *collection;

	zephir_fetch_params(0, 1, 0, &collection);



	zephir_update_property_this(this_ptr, SL("_collection"), collection TSRMLS_CC);

}

PHP_METHOD(My_Mongo_Collection, getCollection) {


	RETURN_MEMBER(this_ptr, "_collection");

}

PHP_METHOD(My_Mongo_Collection, setCollectionName) {

	zval *collectionName;

	zephir_fetch_params(0, 1, 0, &collectionName);



	zephir_update_property_this(this_ptr, SL("_collectionName"), collectionName TSRMLS_CC);

}

PHP_METHOD(My_Mongo_Collection, getCollectionName) {


	RETURN_MEMBER(this_ptr, "_collectionName");

}

PHP_METHOD(My_Mongo_Collection, setDatabaseName) {

	zval *databaseName;

	zephir_fetch_params(0, 1, 0, &databaseName);



	zephir_update_property_this(this_ptr, SL("_databaseName"), databaseName TSRMLS_CC);

}

PHP_METHOD(My_Mongo_Collection, getDatabaseName) {


	RETURN_MEMBER(this_ptr, "_databaseName");

}

PHP_METHOD(My_Mongo_Collection, setClusterName) {

	zval *clusterName;

	zephir_fetch_params(0, 1, 0, &clusterName);



	zephir_update_property_this(this_ptr, SL("_clusterName"), clusterName TSRMLS_CC);

}

PHP_METHOD(My_Mongo_Collection, getClusterName) {


	RETURN_MEMBER(this_ptr, "_clusterName");

}

PHP_METHOD(My_Mongo_Collection, setCollectionOptions) {

	zval *collectionOptions;

	zephir_fetch_params(0, 1, 0, &collectionOptions);



	zephir_update_property_this(this_ptr, SL("_collectionOptions"), collectionOptions TSRMLS_CC);

}

PHP_METHOD(My_Mongo_Collection, getCollectionOptions) {


	RETURN_MEMBER(this_ptr, "_collectionOptions");

}

PHP_METHOD(My_Mongo_Collection, setNoAppendQuery) {

	zval *noAppendQuery;

	zephir_fetch_params(0, 1, 0, &noAppendQuery);



	zephir_update_property_this(this_ptr, SL("_noAppendQuery"), noAppendQuery TSRMLS_CC);

}

PHP_METHOD(My_Mongo_Collection, getNoAppendQuery) {


	RETURN_MEMBER(this_ptr, "_noAppendQuery");

}

PHP_METHOD(My_Mongo_Collection, __construct) {

	zval *collectionOptions = NULL, *_0, *_2;
	zval *collectionName_param = NULL, *databaseName_param = NULL, *clusterName_param = NULL, *collectionOptions_param = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;
	zval *collectionName = NULL, *databaseName = NULL, *clusterName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &collectionName_param, &databaseName_param, &clusterName_param, &collectionOptions_param);

	if (unlikely(Z_TYPE_P(collectionName_param) != IS_STRING && Z_TYPE_P(collectionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'collectionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(collectionName_param) == IS_STRING)) {
		zephir_get_strval(collectionName, collectionName_param);
	} else {
		ZEPHIR_INIT_VAR(collectionName);
		ZVAL_EMPTY_STRING(collectionName);
	}
	if (!databaseName_param) {
		ZEPHIR_INIT_VAR(databaseName);
		ZVAL_EMPTY_STRING(databaseName);
	} else {
	if (unlikely(Z_TYPE_P(databaseName_param) != IS_STRING && Z_TYPE_P(databaseName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'databaseName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(databaseName_param) == IS_STRING)) {
		zephir_get_strval(databaseName, databaseName_param);
	} else {
		ZEPHIR_INIT_VAR(databaseName);
		ZVAL_EMPTY_STRING(databaseName);
	}
	}
	if (!clusterName_param) {
		ZEPHIR_INIT_VAR(clusterName);
		ZVAL_EMPTY_STRING(clusterName);
	} else {
	if (unlikely(Z_TYPE_P(clusterName_param) != IS_STRING && Z_TYPE_P(clusterName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clusterName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(clusterName_param) == IS_STRING)) {
		zephir_get_strval(clusterName, clusterName_param);
	} else {
		ZEPHIR_INIT_VAR(clusterName);
		ZVAL_EMPTY_STRING(clusterName);
	}
	}
	if (!collectionOptions_param) {
	ZEPHIR_INIT_VAR(collectionOptions);
	array_init(collectionOptions);
	} else {
	collectionOptions = collectionOptions_param;

	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 16, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "set", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "inc", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "unset", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "rename", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "setOnInsert", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "addToSet", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pop", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pullAll", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pull", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pushAll", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "push", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "each", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "slice", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sort", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "bit", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "isolated", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("_updateHaystack"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "and", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "or", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "nor", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "not", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "where", 1);
	zephir_array_fast_append(_2, _1);
	zephir_update_property_this(this_ptr, SL("_queryHaystack"), _2 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_collectionOptions"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_collectionName"), collectionName TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	if (ZEPHIR_IS_EMPTY(databaseName)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "ICCv1", 1);
	} else {
		ZEPHIR_CPY_WRT(_3, databaseName);
	}
	zephir_update_property_this(this_ptr, SL("_databaseName"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	if (ZEPHIR_IS_EMPTY(clusterName)) {
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "defaultOptions", 1);
	} else {
		ZEPHIR_CPY_WRT(_4, clusterName);
	}
	zephir_update_property_this(this_ptr, SL("_clusterName"), _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	if (ZEPHIR_IS_EMPTY(collectionOptions)) {
		ZEPHIR_INIT_NVAR(_5);
		array_init(_5);
	} else {
		ZEPHIR_CPY_WRT(_5, collectionOptions);
	}
	zephir_update_property_this(this_ptr, SL("_collectionOptions"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Mongo_Collection, setMongoClient) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *client;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &client);



	zephir_update_property_this(this_ptr, SL("_client"), client TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initdb", NULL, 2);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

PHP_METHOD(My_Mongo_Collection, getMongoClient) {


	RETURN_MEMBER(this_ptr, "_client");

}

PHP_METHOD(My_Mongo_Collection, initCollection) {

	zval *_0, *_1 = NULL, *_2, *_3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initdb", NULL, 2);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_databaseName"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_collectionName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "selectcollection", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_collection"), _1 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "_collection");

}

PHP_METHOD(My_Mongo_Collection, initDB) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "please invoke method setMongoClient before initDB", "my/mongo/collection.zep", 115);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_databaseName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "selectdb", NULL, 0, _3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_db"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Mongo_Collection, initAdmin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "please invoke method setMongoClient before initAdmin", "my/mongo/collection.zep", 123);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_admin"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "admin", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, _2, "selectdb", NULL, 0, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_admin"), _3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Mongo_Collection, initBackup) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "please invoke method setMongoClient before initBackup", "my/mongo/collection.zep", 134);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_backup"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "backup", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, _2, "selectdb", NULL, 0, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_backup"), _3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Mongo_Collection, initMapreduce) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "please invoke method setMongoClient before initMapreduce", "my/mongo/collection.zep", 145);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_mapreduce"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "mapreduce", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, _2, "selectdb", NULL, 0, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mapreduce"), _3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(My_Mongo_Collection, initGridFs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_5 = NULL;
	zval *_0, *_1, *_2, _3, *_4, *_6, *_7;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "please invoke method setMongoClient before init", "my/mongo/collection.zep", 156);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "please invoke method initdb before initGridFs", "my/mongo/collection.zep", 159);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_fs"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_2)) {
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "\\MongoGridFS", 0);
		if (zephir_class_exists(&_3, 1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_4);
			if (!_5) {
				_5 = zend_fetch_class(SL("MongoGridFS"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			}
			object_init_ex(_4, _5);
			if (zephir_has_constructor(_4 TSRMLS_CC)) {
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_7);
				ZVAL_STRING(_7, "icc_", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 0, _6, _7);
				zephir_check_temp_parameter(_7);
				zephir_check_call_status();
			}
			zephir_update_property_this(this_ptr, SL("_fs"), _4 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 添加查询扩展参数__REMOVED__ 
 *
 */
PHP_METHOD(My_Mongo_Collection, appendQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *_0, *_1, *_3, *_4 = NULL;
	zval *query = NULL, *keys = NULL, *intersect = NULL, *_2 = NULL, *_5 = NULL, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &query_param);

	if (!query_param) {
	ZEPHIR_INIT_VAR(query);
	array_init(query);
	} else {
	query = query_param;

	}
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_INIT_VAR(intersect);
	array_init(intersect);


	if (ZEPHIR_IS_EMPTY(query)) {
		ZEPHIR_INIT_NVAR(query);
		array_init(query);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_noAppendQuery"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		RETURN_CTOR(query);
	}
	if (1 == 1) {
		ZEPHIR_INIT_VAR(_1);
		zephir_array_keys(_1, query TSRMLS_CC);
		zephir_get_arrval(_2, _1);
		ZEPHIR_CPY_WRT(keys, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_queryHaystack"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_4, "array_intersect", NULL, 3, keys, _3);
		zephir_check_call_status();
		zephir_get_arrval(_5, _4);
		ZEPHIR_CPY_WRT(intersect, _5);
	}
	if (!(ZEPHIR_IS_EMPTY(intersect))) {
		ZEPHIR_INIT_NVAR(query);
		zephir_create_array(query, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6);
		zephir_create_array(_6, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		zephir_create_array(_7, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_7, SL("__REMOVED__"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(_6, _7);
		zephir_array_fast_append(_6, query);
		zephir_array_update_string(&query, SL("$and"), &_6, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_string(&query, SL("__REMOVED__"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(query);

}

/**
 * 检查某个数组中，是否包含某个键
 *
 * @param array array            
 * @param array keys            
 * @return boolean
 */
PHP_METHOD(My_Mongo_Collection, checkKeyExistInArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *arr_param = NULL, *keys = NULL, *key = NULL, *items = NULL, **_2, *_3 = NULL, *_5 = NULL;
	zval *arr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &arr_param, &keys);

	arr = arr_param;

	ZEPHIR_SEPARATE_PARAM(keys);


	if (Z_TYPE_P(keys) == IS_STRING) {
		ZEPHIR_INIT_NVAR(keys);
		zephir_create_array(keys, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(keys, keys);
	}
	zephir_is_iterable(arr, &_1, &_0, 0, 0, "my/mongo/collection.zep", 235);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(items, _2);
		ZEPHIR_CALL_FUNCTION(&_3, "in_array", &_4, 4, key, keys, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			RETURN_MM_BOOL(1);
		}
		if (Z_TYPE_P(items) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "checkkeyexistinarray", &_6, 5, items, keys);
			zephir_check_call_status();
			if (zephir_is_true(_5)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * ICC采用_id自动分片机制，故需要判断是否增加片键字段，用于分片集合update数据时使用upsert:true的情况
 *
 * @param array query            
 * @return multitype: Ambigous multitype:\MongoId >
 */
PHP_METHOD(My_Mongo_Collection, addSharedKeyToQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *_0 = NULL, *_1 = NULL, *_3, *_4 = NULL, *_8 = NULL;
	zval *query = NULL, *keys = NULL, *intersect = NULL, *_2 = NULL, *_5 = NULL, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &query_param);

	if (!query_param) {
	ZEPHIR_INIT_VAR(query);
	array_init(query);
	} else {
		zephir_get_arrval(query, query_param);
	}
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_INIT_VAR(intersect);
	array_init(intersect);


	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "query must be array", "my/mongo/collection.zep", 247);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkkeyexistinarray", NULL, 5, query, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		RETURN_CTOR(query);
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_array_keys(_1, query TSRMLS_CC);
	zephir_get_arrval(_2, _1);
	ZEPHIR_CPY_WRT(keys, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_queryHaystack"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "array_intersect", NULL, 3, keys, _3);
	zephir_check_call_status();
	zephir_get_arrval(_5, _4);
	ZEPHIR_CPY_WRT(intersect, _5);
	if (!(ZEPHIR_IS_EMPTY(intersect))) {
		ZEPHIR_INIT_NVAR(query);
		zephir_create_array(query, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6);
		zephir_create_array(_6, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		zephir_create_array(_7, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8);
		object_init_ex(_8, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
		if (zephir_has_constructor(_8 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _8, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&_7, SL("_id"), &_8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(_6, _7);
		zephir_array_fast_append(_6, query);
		zephir_array_update_string(&query, SL("$and"), &_6, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(_8);
		object_init_ex(_8, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
		if (zephir_has_constructor(_8 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _8, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&query, SL("_id"), &_8, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(query);

}

/**
 * 处理检索条件
 *
 * @param string text            
 */
PHP_METHOD(My_Mongo_Collection, search) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *_0, *_1, *_2 = NULL, *_3;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(text, text_param);


	object_init_ex(return_value, zephir_get_internal_ce(SS("mongoregex") TSRMLS_CC));
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "/[\\s\r\t\n]/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, ".*", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 6, _0, _1, text);
		zephir_check_temp_parameter(_0);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "/", _2, "/i");
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _3);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * aggregate框架指令达成
 *
 * @return mixed
 */
PHP_METHOD(My_Mongo_Collection, aggregate) {

	zephir_fcall_cache_entry *_5 = NULL;
	zval *_3 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pipeline, *_0, *_1, *_2, *first = NULL, *_6 = NULL, *_7, *_8, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pipeline);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_noAppendQuery"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		zephir_array_fetch_long(&_1, pipeline, 0, PH_READONLY, "my/mongo/collection.zep", 294 TSRMLS_CC);
		zephir_array_fetch_long(&_2, pipeline, 0, PH_READONLY, "my/mongo/collection.zep", 303 TSRMLS_CC);
		if (zephir_array_isset_string(_1, SS("$geoNear"))) {
			Z_SET_ISREF_P(pipeline);
			ZEPHIR_CALL_FUNCTION(&first, "array_shift", NULL, 7, pipeline);
			Z_UNSET_ISREF_P(pipeline);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_3);
			zephir_create_array(_3, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4);
			zephir_create_array(_4, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&_4, SL("__REMOVED__"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_3, SL("$match"), &_4, PH_COPY | PH_SEPARATE);
			Z_SET_ISREF_P(pipeline);
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", &_5, 8, pipeline, _3);
			Z_UNSET_ISREF_P(pipeline);
			zephir_check_call_status();
			Z_SET_ISREF_P(pipeline);
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", &_5, 8, pipeline, first);
			Z_UNSET_ISREF_P(pipeline);
			zephir_check_call_status();
		} else if (zephir_array_isset_string(_2, SS("$match"))) {
			zephir_array_fetch_long(&_7, pipeline, 0, PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 305 TSRMLS_CC);
			zephir_array_fetch_string(&_8, _7, SL("$match"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 305 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_6, this_ptr, "appendquery", NULL, 9, _8);
			zephir_check_call_status();
			zephir_array_update_multi(&pipeline, &_6 TSRMLS_CC, SL("ls"), 3, 0, SL("match"));
		} else {
			ZEPHIR_INIT_NVAR(_3);
			zephir_create_array(_3, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_4);
			zephir_create_array(_4, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&_4, SL("__REMOVED__"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_3, SL("$match"), &_4, PH_COPY | PH_SEPARATE);
			Z_SET_ISREF_P(pipeline);
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", &_5, 8, pipeline, _3);
			Z_UNSET_ISREF_P(pipeline);
			zephir_check_call_status();
		}
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_9, "aggregate", NULL, 0, pipeline);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 批量插入数据
 *
 * @see MongoCollection::batchInsert()
 */
PHP_METHOD(My_Mongo_Collection, batchInsert) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *documents_param = NULL, *options_param = NULL, *row = NULL, **_2, *_3 = NULL, *_4 = NULL, *_5;
	zval *documents = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &documents_param, &options_param);

	documents = documents_param;

	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	zephir_is_iterable(documents, &_1, &_0, 0, 0, "my/mongo/collection.zep", 330);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(row, _2);
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
		if (zephir_has_constructor(_3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&row, SL("__CREATE_TIME__"), &_3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4);
		object_init_ex(_4, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
		if (zephir_has_constructor(_4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&row, SL("__MODIFY_TIME__"), &_4, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&row, SL("__REMOVED__"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_5, "batchinsert", NULL, 0, documents, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 统计符合条件的数量
 *
 * @see MongoCollection::count()
 */
PHP_METHOD(My_Mongo_Collection, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *limit = NULL, *skip = NULL, *_0 = NULL, *_1;
	zval *query = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &query_param, &limit, &skip);

	if (!query_param) {
	ZEPHIR_INIT_VAR(query);
	array_init(query);
	} else {
	query = query_param;

	}
	if (!limit) {
		limit = ZEPHIR_GLOBAL(global_null);
	}
	if (!skip) {
		skip = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "appendquery", NULL, 9, query);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "count", NULL, 0, query, limit, skip);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 根据指定字段
 *
 * @param string key            
 * @param array query            
 */
PHP_METHOD(My_Mongo_Collection, distinct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL;
	zval *key_param = NULL, *query_param = NULL, *_0 = NULL, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &query_param);

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
	if (!query_param) {
	ZEPHIR_INIT_VAR(query);
	array_init(query);
	} else {
	query = query_param;

	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "appendquery", NULL, 9, query);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "distinct", NULL, 0, key, query);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 直接禁止drop操作,注意备份表中只包含当前集合中的有效数据，__REMOVED__为true的不在此列
 *
 * 仅适合数据量操作能在脚本生命周期内能够完成的
 *
 * @see MongoCollection::drop()
 */
PHP_METHOD(My_Mongo_Collection, drop) {

	zval *_9 = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL;
	zephir_nts_static zend_class_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *targetCollection, *target, *cursor = NULL, *row = NULL, _0, *_1 = NULL, *_2, *_4, *_5, *_6 = NULL, *_8, *_11;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "YmdHis", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 10, &_0);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_collectionName"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(targetCollection);
	ZEPHIR_CONCAT_SVSV(targetCollection, "bak_", _1, "_", _2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initbackup", NULL, 11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(target);
	if (!_3) {
		_3 = zend_fetch_class(SL("MongoCollection"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(target, _3);
	if (zephir_has_constructor(target TSRMLS_CC)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_backup"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, target, "__construct", NULL, 0, _4, targetCollection);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	ZEPHIR_CALL_METHOD(&cursor, this_ptr, "find", NULL, 0, _5);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_6, cursor, "hasnext", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_6))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&row, cursor, "getnext", &_7, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_8, row, SL("_id"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 378 TSRMLS_CC);
		zephir_array_update_string(&row, SL("__OLD_ID__"), &_8, PH_COPY | PH_SEPARATE);
		zephir_array_unset_string(&row, SS("_id"), PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_9);
		zephir_create_array(_9, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(_9, SS("w"), 0);
		ZEPHIR_CALL_METHOD(NULL, target, "insert", &_10, 0, row, _9);
		zephir_check_call_status();
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_11, "drop", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 物理删除数据集合
 */
PHP_METHOD(My_Mongo_Collection, physicalDrop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "drop", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 新驱动已经抛弃了该方法，但是为了保持一致性，继续支持，但是不建议采用
 *
 * @see MongoCollection::ensureIndex()
 */
PHP_METHOD(My_Mongo_Collection, ensureIndex) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *options_param = NULL;
	zval *keys = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keys_param, &options_param);

	keys = keys_param;

	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
	options = options_param;

	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "createindex", NULL, 0, keys, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 新的写法，创建索引
 *
 * @param array keys            
 * @param array options            
 */
PHP_METHOD(My_Mongo_Collection, createIndex) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *options_param = NULL, *_0 = NULL, *defaultOptions, *_1, *_2 = NULL, _3, _4, _5, *_6 = NULL, *_7;
	zval *keys = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keys_param, &options_param);

	keys = keys_param;

	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
	options = options_param;

	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkindexexist", NULL, 0, keys);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_TRUE(_0))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(defaultOptions);
	array_init(defaultOptions);
	zephir_array_update_string(&defaultOptions, SL("background"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_array_update_string(&defaultOptions, SL("w"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	if (ZEPHIR_IS_STRING_IDENTICAL(options, "")) {
		ZEPHIR_CPY_WRT(_2, defaultOptions);
	} else {
		ZEPHIR_INIT_NVAR(_2);
		zephir_fast_array_merge(_2, &(defaultOptions), &(options) TSRMLS_CC);
	}
	ZEPHIR_CPY_WRT(options, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "1.5.0", 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, ">=", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "version_compare", NULL, 12, &_3, &_4, &_5);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_7, "createindex", NULL, 0, keys, options);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_7, "ensureindex", NULL, 0, keys, options);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * 检测集合的某个索引是否存在
 *
 * @param array keys            
 * @return boolean
 */
PHP_METHOD(My_Mongo_Collection, checkIndexExist) {

	HashTable *_3;
	HashPosition _2;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *indexes = NULL, *index = NULL, *_0, **_4, *_5;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	keys = keys_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&indexes, _0, "getindexinfo", NULL, 0);
	zephir_check_call_status();
	_1 = !(ZEPHIR_IS_EMPTY(indexes));
	if (_1) {
		_1 = Z_TYPE_P(indexes) == IS_ARRAY;
	}
	if (_1) {
		zephir_is_iterable(indexes, &_3, &_2, 0, 0, "my/mongo/collection.zep", 444);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(index, _4);
			zephir_array_fetch_string(&_5, index, SL("key"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 440 TSRMLS_CC);
			if (ZEPHIR_IS_EQUAL(_5, keys)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * 查询符合条件的项目，自动排除__REMOVED__:true的结果集
 *
 * @see MongoCollection::find()
 */
PHP_METHOD(My_Mongo_Collection, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *fields_param = NULL, *_0 = NULL, *_1 = NULL, *_2;
	zval *query = NULL, *fields = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &query_param, &fields_param);

	if (!query_param) {
	ZEPHIR_INIT_VAR(query);
	array_init(query);
	} else {
	query = query_param;

	}
	if (!fields_param) {
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	} else {
	fields = fields_param;

	}


	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_IS_EMPTY(fields)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init(_0);
	} else {
		ZEPHIR_CPY_WRT(_0, fields);
	}
	ZEPHIR_CPY_WRT(fields, _0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "appendquery", NULL, 9, query);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_2, "find", NULL, 0, query, fields);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 查询符合条件的一条数据
 *
 * @see MongoCollection::findOne()
 */
PHP_METHOD(My_Mongo_Collection, findOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *fields_param = NULL, *_0 = NULL, *_1 = NULL, *_2;
	zval *query = NULL, *fields = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &query_param, &fields_param);

	if (!query_param) {
	ZEPHIR_INIT_VAR(query);
	array_init(query);
	} else {
	query = query_param;

	}
	if (!fields_param) {
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	} else {
	fields = fields_param;

	}


	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_IS_EMPTY(fields)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init(_0);
	} else {
		ZEPHIR_CPY_WRT(_0, fields);
	}
	ZEPHIR_CPY_WRT(fields, _0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "appendquery", NULL, 9, query);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_2, "findone", NULL, 0, query, fields);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取符合条件的全部数据
 *
 * @param array query            
 * @param array sort            
 * @param int skip            
 * @param int limit            
 * @param array fields            
 * @return array
 */
PHP_METHOD(My_Mongo_Collection, findAll) {

	int skip, limit, ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *sort_param = NULL, *skip_param = NULL, *limit_param = NULL, *fields_param = NULL, *_0 = NULL, *cursor = NULL, *_1 = NULL, *_2, *_3, *result = NULL;
	zval *query = NULL, *sort = NULL, *fields = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &query_param, &sort_param, &skip_param, &limit_param, &fields_param);

	if (!query_param) {
		ZEPHIR_INIT_VAR(query);
		array_init(query);
	} else {
	query = query_param;

	}
	if (!sort_param) {
		ZEPHIR_INIT_VAR(sort);
		array_init(sort);
	} else {
	sort = sort_param;

	}
	if (!skip_param) {
		skip = 0;
	} else {
		skip = zephir_get_intval(skip_param);
	}
	if (!limit_param) {
		limit = 0;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
	fields = fields_param;

	}


	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_IS_EMPTY(fields)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init(_0);
	} else {
		ZEPHIR_CPY_WRT(_0, fields);
	}
	ZEPHIR_CPY_WRT(fields, _0);
	ZEPHIR_CALL_METHOD(&cursor, this_ptr, "find", NULL, 0, query, fields);
	zephir_check_call_status();
	if (!(zephir_is_instance_of(cursor, SL("MongoCursor") TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2);
		zephir_json_encode(_2, &(_2), query, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SV(_3, "query error:", _2);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 13, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "my/mongo/collection.zep", 489 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(ZEPHIR_IS_EMPTY(sort))) {
		ZEPHIR_CALL_METHOD(NULL, cursor, "sort", NULL, 0, sort);
		zephir_check_call_status();
	}
	if (skip > 0) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, skip);
		ZEPHIR_CALL_METHOD(NULL, cursor, "skip", NULL, 0, _1);
		zephir_check_call_status();
	}
	if (limit > 0) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, limit);
		ZEPHIR_CALL_METHOD(NULL, cursor, "limit", NULL, 0, _1);
		zephir_check_call_status();
	}
	if (zephir_zval_is_traversable(cursor TSRMLS_CC)) {
		ZEPHIR_CALL_FUNCTION(&result, "iterator_to_array", NULL, 14, cursor, ZEPHIR_GLOBAL(global_false));
		zephir_check_call_status();
		RETURN_CCTOR(result);
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * findAndModify操作
 * 特别注意：__REMOVED__ __MODIFY_TIME__ __CREATE_TIME__ 3个系统保留变量在update参数中的使用
 *
 * @param array query            
 * @param array update            
 * @param array fields            
 * @param array options            
 * @return array
 */
PHP_METHOD(My_Mongo_Collection, findAndModify) {

	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *update_param = NULL, *fields_param = NULL, *options_param = NULL, *_0 = NULL, *_1, *_2 = NULL, *_4, *_5 = NULL, *_6;
	zval *query = NULL, *update = NULL, *fields = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &query_param, &update_param, &fields_param, &options_param);

	query = query_param;

	if (!update_param) {
	ZEPHIR_INIT_VAR(update);
	array_init(update);
	} else {
	update = update_param;

	}
	if (!fields_param) {
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	} else {
	fields = fields_param;

	}
	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
	options = options_param;

	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "appendquery", NULL, 9, query);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "count", NULL, 0, query);
	zephir_check_call_status();
	_3 = ZEPHIR_IS_LONG(_2, 0);
	if (_3) {
		zephir_array_fetch_string(&_4, options, SL("upsert"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 526 TSRMLS_CC);
		_3 = !(ZEPHIR_IS_EMPTY(_4));
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "addsharedkeytoquery", NULL, 15, query);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(query, _5);
	} else {
		zephir_array_unset_string(&options, SS("upsert"), PH_SEPARATE);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_6, "findandmodify", NULL, 0, query, update, fields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 增加findAndModify方法
 * 特别注意：__REMOVED__ __MODIFY_TIME__ __CREATE_TIME__ 3个系统保留变量在update参数中的使用
 *
 * @param array option            
 * @param string collection            
 * @return mixed array|null
 */
PHP_METHOD(My_Mongo_Collection, findAndModifyByCommand) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, *collection_param = NULL, *cmd, *targetCollection = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, *_5, *_6 = NULL, *_7, *_8;
	zval *option = NULL, *collection = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &option_param, &collection_param);

	option = option_param;

	if (!collection_param) {
	ZEPHIR_INIT_VAR(collection);
	array_init(collection);
	} else {
	collection = collection_param;

	}


	ZEPHIR_INIT_VAR(cmd);
	array_init(cmd);
	if (ZEPHIR_IS_STRING_IDENTICAL(collection, "")) {
		ZEPHIR_OBS_VAR(targetCollection);
		zephir_read_property_this(&targetCollection, this_ptr, SL("_collection"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(targetCollection, collection);
	}
	zephir_array_update_string(&cmd, SL("findandmodify"), &targetCollection, PH_COPY | PH_SEPARATE);
	if (zephir_array_isset_string(option, SS("query"))) {
		zephir_array_fetch_string(&_1, option, SL("query"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 549 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "appendquery", NULL, 9, _1);
		zephir_check_call_status();
		zephir_array_update_string(&cmd, SL("query"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(option, SS("sort"))) {
		zephir_array_fetch_string(&_1, option, SL("sort"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 552 TSRMLS_CC);
		zephir_array_update_string(&cmd, SL("sort"), &_1, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(option, SS("remove"))) {
		ZEPHIR_INIT_VAR(_2);
		zephir_array_fetch_string(&_1, option, SL("remove"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 555 TSRMLS_CC);
		if (Z_TYPE_P(_1) == IS_BOOL) {
			ZEPHIR_OBS_NVAR(_2);
			zephir_array_fetch_string(&_2, option, SL("remove"), PH_NOISY, "my/mongo/collection.zep", 555 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_BOOL(_2, 0);
		}
		zephir_array_update_string(&cmd, SL("remove"), &_2, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(option, SS("update"))) {
		zephir_array_fetch_string(&_1, option, SL("update"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 558 TSRMLS_CC);
		zephir_array_update_string(&cmd, SL("update"), &_1, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(option, SS("new"))) {
		ZEPHIR_INIT_LNVAR(_2);
		zephir_array_fetch_string(&_1, option, SL("new"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 561 TSRMLS_CC);
		if (Z_TYPE_P(_1) == IS_BOOL) {
			ZEPHIR_OBS_NVAR(_2);
			zephir_array_fetch_string(&_2, option, SL("new"), PH_NOISY, "my/mongo/collection.zep", 561 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_BOOL(_2, 0);
		}
		zephir_array_update_string(&cmd, SL("new"), &_2, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(option, SS("fields"))) {
		zephir_array_fetch_string(&_1, option, SL("fields"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 564 TSRMLS_CC);
		zephir_array_update_string(&cmd, SL("fields"), &_1, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(option, SS("upsert"))) {
		ZEPHIR_INIT_LNVAR(_2);
		zephir_array_fetch_string(&_1, option, SL("upsert"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 567 TSRMLS_CC);
		if (Z_TYPE_P(_1) == IS_BOOL) {
			ZEPHIR_OBS_NVAR(_2);
			zephir_array_fetch_string(&_2, option, SL("upsert"), PH_NOISY, "my/mongo/collection.zep", 567 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_BOOL(_2, 0);
		}
		zephir_array_update_string(&cmd, SL("upsert"), &_2, PH_COPY | PH_SEPARATE);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, cmd, SL("query"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 569 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, _3, "count", NULL, 0, _1);
	zephir_check_call_status();
	_4 = ZEPHIR_IS_LONG(_0, 0);
	if (_4) {
		zephir_array_fetch_string(&_5, option, SL("upsert"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 569 TSRMLS_CC);
		_4 = !(ZEPHIR_IS_EMPTY(_5));
	}
	if (_4) {
		zephir_array_fetch_string(&_7, cmd, SL("query"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 570 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "addsharedkeytoquery", NULL, 15, _7);
		zephir_check_call_status();
		zephir_array_update_string(&cmd, SL("query"), &_6, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_unset_string(&cmd, SS("upsert"), PH_SEPARATE);
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_8, "command", NULL, 0, cmd);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 插入特定的数据,并保持insert第一个参数a在没有_id的时候添加_id属性
 *
 * @param array object            
 * @param array options            
 */
PHP_METHOD(My_Mongo_Collection, insertRef) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *a, *options_param = NULL, *res = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &a, &options_param);

	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
	options = options_param;

	}


	ZEPHIR_CALL_METHOD(&res, this_ptr, "insertbyfindandmodify", NULL, 0, a);
	zephir_check_call_status();
	if (zephir_array_isset_string(res, SS("ok"))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(res);

}

/**
 * 插入特定的数据，注意此方法無法針對a添加_id属性，详见参数丢失原因的文档说明
 * 解决这个问题，请使用上面的方法insertRef
 * 注意因为参数检查的原因，无法直接覆盖insert方法并采用引用，如下原因
 * <b>Strict Standards</b>: Declaration of My\Common\MongoCollection::insert() should be compatible with MongoCollection::insert(array_of_fields_OR_object, array options = NULL)
 *
 * @param array object            
 * @param array options            
 */
PHP_METHOD(My_Mongo_Collection, insert) {

	zend_bool _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *options_param = NULL, *defaultOptions, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4, *_6, *_7;
	zval *a = NULL, *options = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &a_param, &options_param);

	a = a_param;

	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
	options = options_param;

	}
	ZEPHIR_INIT_VAR(defaultOptions);
	array_init(defaultOptions);


	if (ZEPHIR_IS_EMPTY(a)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "object is NULL", "my/mongo/collection.zep", 605);
		return;
	}
	zephir_array_update_string(&defaultOptions, SL("fsync"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_IS_STRING_IDENTICAL(options, "")) {
		ZEPHIR_CPY_WRT(_0, defaultOptions);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_array_merge(_0, &(defaultOptions), &(options) TSRMLS_CC);
	}
	ZEPHIR_CPY_WRT(options, _0);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "__CREATE_TIME__", 1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "__MODIFY_TIME__", 1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "__REMOVED__", 1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "array_unset_recursive", NULL, 16, a, _2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(a, _1);
	if (!(zephir_array_isset_string(a, SS("__CREATE_TIME__")))) {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
		if (zephir_has_constructor(_3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&a, SL("__CREATE_TIME__"), &_3, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(a, SS("__MODIFY_TIME__")))) {
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
		if (zephir_has_constructor(_4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&a, SL("__MODIFY_TIME__"), &_4, PH_COPY | PH_SEPARATE);
	}
	_5 = !(zephir_array_isset_string(a, SS("__REMOVED__")));
	if (_5) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_noAppendQuery"), PH_NOISY_CC);
		_5 = !zephir_is_true(_6);
	}
	if (_5) {
		zephir_array_update_string(&a, SL("__REMOVED__"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_7, "insert", NULL, 0, a, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 通过findAndModify的方式，插入数据。
 * 这样可以使用a["a.b"]的方式插入结构为{a:{b:xxx}}的数据,这是insert所不能办到的
 * 采用update也可以实现类似的效果，区别在于findAndModify可以返回插入之后的新数据，更接近insert的原始行为
 *
 * @param array a            
 * @return array
 */
PHP_METHOD(My_Mongo_Collection, insertByFindAndModify) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *a = NULL, *query, *fields, *options, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &a);

	ZEPHIR_SEPARATE_PARAM(a);


	if (ZEPHIR_IS_EMPTY(a)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "a is NULL", "my/mongo/collection.zep", 644);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "__CREATE_TIME__", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "__MODIFY_TIME__", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "__REMOVED__", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "array_unset_recursive", NULL, 16, a, _1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(a, _0);
	if (!(zephir_array_isset_string(a, SS("__CREATE_TIME__")))) {
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
		if (zephir_has_constructor(_2 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&a, SL("__CREATE_TIME__"), &_2, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(a, SS("__MODIFY_TIME__")))) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
		if (zephir_has_constructor(_3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&a, SL("__MODIFY_TIME__"), &_3, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(a, SS("__REMOVED__")))) {
		zephir_array_update_string(&a, SL("__REMOVED__"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(query);
	zephir_create_array(query, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	object_init_ex(_3, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
	if (zephir_has_constructor(_3 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_array_update_string(&query, SL("_id"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(a);
	zephir_create_array(a, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&a, SL("$set"), &a, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(fields);
	ZVAL_NULL(fields);
	ZEPHIR_INIT_VAR(options);
	zephir_create_array(options, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&options, SL("new"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&options, SL("upsert"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_4, "findandmodify", NULL, 0, query, a, fields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除指定范围的数据
 *
 * @param array criteria            
 * @param array options            
 */
PHP_METHOD(My_Mongo_Collection, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1;
	zval *criteria_param = NULL, *options_param = NULL, *defaultOptions = NULL, *_0 = NULL, *_2, *_3 = NULL, *_4;
	zval *criteria = NULL, *options = NULL, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &criteria_param, &options_param);

	if (!criteria_param) {
	ZEPHIR_INIT_VAR(criteria);
	array_init(criteria);
	} else {
	criteria = criteria_param;

	}
	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
	options = options_param;

	}
	ZEPHIR_INIT_VAR(defaultOptions);
	array_init(defaultOptions);


	if (ZEPHIR_IS_STRING_IDENTICAL(criteria, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "criteria is NULL", "my/mongo/collection.zep", 690);
		return;
	}
	ZEPHIR_INIT_NVAR(defaultOptions);
	zephir_create_array(defaultOptions, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&defaultOptions, SL("justOne"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&defaultOptions, SL("fsync"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_IS_STRING_IDENTICAL(options, "")) {
		ZEPHIR_CPY_WRT(_0, defaultOptions);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_array_merge(_0, &(defaultOptions), &(options) TSRMLS_CC);
	}
	ZEPHIR_CPY_WRT(options, _0);
	_1 = zephir_array_isset_string(options, SS("justOne"));
	if (_1) {
		zephir_array_fetch_string(&_2, options, SL("justOne"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 701 TSRMLS_CC);
		_1 = !zephir_is_true(_2);
	}
	if (_1) {
		zephir_array_update_string(&options, SL("multiple"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "appendquery", NULL, 9, criteria);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(criteria, _3);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, SL("__REMOVED__"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("set"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(_4, "update", NULL, 0, criteria, _5, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 物理删除指定范围的数据
 *
 * @param array criteria            
 * @param array options            
 */
PHP_METHOD(My_Mongo_Collection, physicalRemove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *criteria_param = NULL, *options_param = NULL, *defaultOptions = NULL, *_0 = NULL, *_1;
	zval *criteria = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &criteria_param, &options_param);

	if (!criteria_param) {
	ZEPHIR_INIT_VAR(criteria);
	array_init(criteria);
	} else {
	criteria = criteria_param;

	}
	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	ZEPHIR_INIT_VAR(defaultOptions);
	array_init(defaultOptions);


	if (ZEPHIR_IS_STRING_IDENTICAL(criteria, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "criteria is NULL", "my/mongo/collection.zep", 722);
		return;
	}
	ZEPHIR_INIT_NVAR(defaultOptions);
	zephir_create_array(defaultOptions, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&defaultOptions, SL("justOne"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&defaultOptions, SL("fsync"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_IS_STRING_IDENTICAL(options, "")) {
		ZEPHIR_CPY_WRT(_0, defaultOptions);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_array_merge(_0, &(defaultOptions), &(options) TSRMLS_CC);
	}
	ZEPHIR_CPY_WRT(options, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "remove", NULL, 0, criteria, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 物理更新数据
 *
 * @param array criteria            
 * @param array object            
 * @param array options            
 * @throws \Exception
 */
PHP_METHOD(My_Mongo_Collection, physicalUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *options = NULL;
	zval *criteria, *obj, *options_param = NULL, *key = NULL, *keys, *defaultOptions, **_2, *_3, *_4 = NULL, *_6 = NULL, *_7 = NULL, *_8, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &criteria, &obj, &options_param);

	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	if (!(Z_TYPE_P(criteria) == IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "criteria is array", "my/mongo/collection.zep", 746);
		return;
	}
	if (ZEPHIR_IS_EMPTY(obj)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "obj is empty", "my/mongo/collection.zep", 750);
		return;
	}
	ZEPHIR_INIT_VAR(keys);
	zephir_array_keys(keys, obj TSRMLS_CC);
	zephir_is_iterable(keys, &_1, &_0, 0, 0, "my/mongo/collection.zep", 761);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(key, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_updateHaystack"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_4, "in_array", &_5, 4, key, _3, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		if (!(zephir_is_true(_4))) {
			ZEPHIR_INIT_NVAR(_6);
			object_init_ex(_6, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_NVAR(_7);
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("_updateHaystack"), PH_NOISY_CC);
			zephir_fast_join_str(_7, SL(","), _8 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_SV(_9, "key must contain ", _7);
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_10, 13, _9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6, "my/mongo/collection.zep", 757 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(defaultOptions);
	zephir_create_array(defaultOptions, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&defaultOptions, SL("upsert"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&defaultOptions, SL("multiple"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&defaultOptions, SL("fsync"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_9);
	if (ZEPHIR_IS_STRING_IDENTICAL(options, "")) {
		ZEPHIR_CPY_WRT(_9, defaultOptions);
	} else {
		ZEPHIR_INIT_NVAR(_9);
		zephir_fast_array_merge(_9, &(defaultOptions), &(options) TSRMLS_CC);
	}
	ZEPHIR_CPY_WRT(options, _9);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_3, "update", NULL, 0, criteria, obj, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 更新指定范围的数据
 *
 * @param array criteria            
 * @param array object            
 * @param array options            
 */
PHP_METHOD(My_Mongo_Collection, update) {

	zend_bool _12;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *options = NULL, *_11, *_15 = NULL, *_16 = NULL;
	zval *criteria = NULL, *obj = NULL, *options_param = NULL, *key = NULL, *keys, *defaultOptions, **_2, *_3, *_4 = NULL, *_6 = NULL, *_7 = NULL, *_8, *_9 = NULL, *_13, *_14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &criteria, &obj, &options_param);

	ZEPHIR_SEPARATE_PARAM(criteria);
	ZEPHIR_SEPARATE_PARAM(obj);
	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	if (!(Z_TYPE_P(criteria) == IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "criteria is array", "my/mongo/collection.zep", 781);
		return;
	}
	if (ZEPHIR_IS_EMPTY(obj)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "object is empty", "my/mongo/collection.zep", 785);
		return;
	}
	ZEPHIR_INIT_VAR(keys);
	zephir_array_keys(keys, obj TSRMLS_CC);
	zephir_is_iterable(keys, &_1, &_0, 0, 0, "my/mongo/collection.zep", 795);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(key, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_updateHaystack"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_4, "in_array", &_5, 4, key, _3, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		if (!(zephir_is_true(_4))) {
			ZEPHIR_INIT_NVAR(_6);
			object_init_ex(_6, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_NVAR(_7);
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("_updateHaystack"), PH_NOISY_CC);
			zephir_fast_join_str(_7, SL(","), _8 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_SV(_9, "key must contain ", _7);
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_10, 13, _9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6, "my/mongo/collection.zep", 792 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(defaultOptions);
	zephir_create_array(defaultOptions, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&defaultOptions, SL("upsert"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&defaultOptions, SL("multiple"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&defaultOptions, SL("fsync"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_9);
	if (ZEPHIR_IS_STRING_IDENTICAL(options, "")) {
		ZEPHIR_CPY_WRT(_9, defaultOptions);
	} else {
		ZEPHIR_INIT_NVAR(_9);
		zephir_fast_array_merge(_9, &(defaultOptions), &(options) TSRMLS_CC);
	}
	ZEPHIR_CPY_WRT(options, _9);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "appendquery", NULL, 9, criteria);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(criteria, _4);
	ZEPHIR_INIT_VAR(_11);
	zephir_create_array(_11, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "__CREATE_TIME__", 1);
	zephir_array_fast_append(_11, _6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "__MODIFY_TIME__", 1);
	zephir_array_fast_append(_11, _6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "__REMOVED__", 1);
	zephir_array_fast_append(_11, _6);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "array_unset_recursive", NULL, 16, obj, _11);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(obj, _4);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "count", NULL, 0, criteria);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_LONG(_4, 0))) {
		_12 = zephir_array_isset_string(options, SS("upsert"));
		if (_12) {
			zephir_array_fetch_string(&_13, options, SL("upsert"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 811 TSRMLS_CC);
			_12 = zephir_is_true(_13);
		}
		if (_12) {
			ZEPHIR_CALL_METHOD(&_14, this_ptr, "addsharedkeytoquery", NULL, 15, criteria);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(criteria, _14);
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_15);
			zephir_create_array(_15, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_16);
			zephir_create_array(_16, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_6);
			object_init_ex(_6, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
			if (zephir_has_constructor(_6 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			zephir_array_update_string(&_16, SL("__CREATE_TIME__"), &_6, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_6);
			object_init_ex(_6, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
			if (zephir_has_constructor(_6 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			zephir_array_update_string(&_16, SL("__MODIFY_TIME__"), &_6, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16, SL("__REMOVED__"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_15, SL("set"), &_16, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, _8, "update", NULL, 0, criteria, _15, options);
			zephir_check_call_status();
		}
	} else {
		zephir_array_unset_string(&options, SS("upsert"), PH_SEPARATE);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_15);
		zephir_create_array(_15, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_16);
		zephir_create_array(_16, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_6);
		object_init_ex(_6, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
		if (zephir_has_constructor(_6 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&_16, SL("__MODIFY_TIME__"), &_6, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_15, SL("set"), &_16, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, _3, "update", NULL, 0, criteria, _15, options);
		zephir_check_call_status();
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_3, "update", NULL, 0, criteria, obj, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 保存并保持引用修改状态
 *
 * @param array a            
 * @param array options            
 * @return mixed
 */
PHP_METHOD(My_Mongo_Collection, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *options_param = NULL, *_0 = NULL, *_1;
	zval *a = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &a_param, &options_param);

	a = a_param;

	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
	options = options_param;

	}


	if (!(zephir_array_isset_string(a, SS("__CREATE_TIME__")))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
		if (zephir_has_constructor(_0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_array_update_string(&a, SL("__CREATE_TIME__"), &_0, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&a, SL("__REMOVED__"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("mongodate") TSRMLS_CC));
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_array_update_string(&a, SL("__MODIFY_TIME__"), &_0, PH_COPY | PH_SEPARATE);
	if (ZEPHIR_IS_STRING(options, "")) {
		ZEPHIR_INIT_NVAR(options);
		zephir_create_array(options, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(options, SS("w"), 1);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "save", NULL, 0, a, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 保存并保持引用修改状态
 *
 * @param array a            
 * @param array options            
 * @return mixed
 */
PHP_METHOD(My_Mongo_Collection, saveRef) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *options_param = NULL;
	zval *a = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &a_param, &options_param);

	a = a_param;

	if (!options_param) {
	ZEPHIR_INIT_VAR(options);
	array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL, 0, a, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 执行DB的command操作,直接运行命令行操作数据库中的数据，慎用
 *
 * @param array command            
 * @return array
 */
PHP_METHOD(My_Mongo_Collection, command) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *command_param = NULL, *_0, *_1;
	zval *command = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &command_param);

	command = command_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, _0, SL("db"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "command", NULL, 0, command);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * mapreduce 错误评价
 *
 */
PHP_METHOD(My_Mongo_Collection, failure) {

	zval *msg = NULL;
	zval *code_param = NULL, *msg_param = NULL, *_0 = NULL;
	int code;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &code_param, &msg_param);

	if (unlikely(Z_TYPE_P(code_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'code' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	code = Z_LVAL_P(code_param);
	if (unlikely(Z_TYPE_P(msg_param) != IS_STRING && Z_TYPE_P(msg_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'msg' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(msg_param) == IS_STRING)) {
		zephir_get_strval(msg, msg_param);
	} else {
		ZEPHIR_INIT_VAR(msg);
		ZVAL_EMPTY_STRING(msg);
	}


	if (Z_TYPE_P(msg) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_json_encode(_0, &(_0), msg, 0  TSRMLS_CC);
		zephir_get_strval(msg, _0);
	}
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	add_assoc_long_ex(return_value, SS("ok"), 0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, code);
	zephir_array_update_string(&return_value, SL("code"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("msg"), &msg, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * 执行map reduce操作,为了防止数据量过大，导致无法完成mapreduce,统一采用集合的方式，取代内存方式
 * 内存方式，不允许执行过程的数据量量超过物理内存的10%，故无法进行大数量分析工作。
 *
 * @param array command            
 */
PHP_METHOD(My_Mongo_Collection, mapReduce) {

	zend_bool _14;
	zephir_nts_static zend_class_entry *_3 = NULL, *_5 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, *_8, *_10, *_11;
	zval *out_param = NULL, *map, *reduce, *query_param = NULL, *finalize = NULL, *method_param = NULL, *scope = NULL, *sort = NULL, *limit = NULL, *arrArgs = NULL, *_0 = NULL, *command, *rst = NULL, *_1, *_2 = NULL, *_4 = NULL, *_6 = NULL, *_9 = NULL, *_12, *_13, *_15, *outMongoCollection, *_16, *_17, _18;
	zval *out = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 7, &out_param, &map, &reduce, &query_param, &finalize, &method_param, &scope, &sort, &limit);

	if (!out_param) {
		ZEPHIR_INIT_VAR(out);
		ZVAL_EMPTY_STRING(out);
	} else {
		zephir_get_strval(out, out_param);
	}
	if (!query_param) {
		ZEPHIR_INIT_VAR(query);
		array_init(query);
	} else {
	query = query_param;

	}
	if (!finalize) {
		finalize = ZEPHIR_GLOBAL(global_null);
	}
	if (!method_param) {
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "replace", 1);
	} else {
	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	}
	if (!scope) {
		scope = ZEPHIR_GLOBAL(global_null);
	}
	if (!sort) {
		sort = ZEPHIR_GLOBAL(global_null);
	}
	if (!limit) {
		limit = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_IS_STRING(out, "")) {
		ZEPHIR_CALL_FUNCTION(&arrArgs, "func_get_args", NULL, 17);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(out);
		ZEPHIR_CALL_FUNCTION(&_0, "serialize", NULL, 18, arrArgs);
		zephir_check_call_status();
		zephir_md5(out, _0);
	}
	ZEPHIR_INIT_VAR(command);
	array_init(command);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	zephir_array_update_string(&command, SL("mapreduce"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	if (zephir_is_instance_of(map, SL("MongoCode") TSRMLS_CC)) {
		ZEPHIR_CPY_WRT(_2, map);
	} else {
		ZEPHIR_INIT_NVAR(_2);
		if (!_3) {
			_3 = zend_fetch_class(SL("MongoCode"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_2, _3);
		if (zephir_has_constructor(_2 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0, map);
			zephir_check_call_status();
		}
	}
	zephir_array_update_string(&command, SL("map"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	if (zephir_is_instance_of(reduce, SL("MongoCode") TSRMLS_CC)) {
		ZEPHIR_CPY_WRT(_4, reduce);
	} else {
		ZEPHIR_INIT_NVAR(_4);
		if (!_5) {
			_5 = zend_fetch_class(SL("MongoCode"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_4, _5);
		if (zephir_has_constructor(_4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 0, reduce);
			zephir_check_call_status();
		}
	}
	zephir_array_update_string(&command, SL("reduce"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "appendquery", NULL, 9, query);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, _0);
	if (!(ZEPHIR_IS_EMPTY(query))) {
		zephir_array_update_string(&command, SL("query"), &query, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(finalize))) {
		ZEPHIR_INIT_VAR(_6);
		if (zephir_is_instance_of(finalize, SL("MongoCode") TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(_6, finalize);
		} else {
			ZEPHIR_INIT_NVAR(_6);
			if (!_7) {
				_7 = zend_fetch_class(SL("MongoCode"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			}
			object_init_ex(_6, _7);
			if (zephir_has_constructor(_6 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 0, finalize);
				zephir_check_call_status();
			}
		}
		zephir_array_update_string(&command, SL("finalize"), &_6, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(sort))) {
		zephir_array_update_string(&command, SL("sort"), &sort, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(limit))) {
		zephir_array_update_string(&command, SL("limit"), &limit, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(scope))) {
		zephir_array_update_string(&command, SL("scope"), &scope, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&command, SL("verbose"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_STRING(_9, "replace", 1);
	zephir_array_fast_append(_8, _9);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "merge", 1);
	zephir_array_fast_append(_8, _9);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "reduce", 1);
	zephir_array_fast_append(_8, _9);
	ZEPHIR_CALL_FUNCTION(&_0, "in_array", NULL, 4, method, _8, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_NVAR(method);
		ZVAL_STRING(method, "replace", 1);
	}
	ZEPHIR_INIT_VAR(_10);
	zephir_create_array(_10, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&_10, Z_STRVAL_P(method), Z_STRLEN_P(method), &out, PH_COPY);
	add_assoc_stringl_ex(_10, SS("db"), SL("mapreduce"), 1);
	zephir_array_update_string(&_10, SL("sharded"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_6);
	ZEPHIR_INIT_VAR(_11);
	zephir_create_array(_11, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "merge", 1);
	zephir_array_fast_append(_11, _9);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "reduce", 1);
	zephir_array_fast_append(_11, _9);
	ZEPHIR_CALL_FUNCTION(&_0, "in_array", NULL, 4, method, _11, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_BOOL(_6, 1);
	} else {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_BOOL(_6, 0);
	}
	zephir_array_update_string(&_10, SL("nonAtomic"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&command, SL("out"), &_10, PH_COPY | PH_SEPARATE);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_13);
	zephir_read_property(&_13, _12, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&rst, _13, "command", NULL, 0, command);
	zephir_check_call_status();
	_14 = zephir_array_isset_string(rst, SS("ok"));
	if (_14) {
		zephir_array_fetch_string(&_15, rst, SL("ok"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 953 TSRMLS_CC);
		_14 = ZEPHIR_IS_LONG(_15, 1);
	}
	if (_14) {
		ZEPHIR_INIT_VAR(outMongoCollection);
		object_init_ex(outMongoCollection, my_mongo_collection_ce);
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("_clusterName"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "mapreduce", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, outMongoCollection, "__construct", NULL, 19, out, _9, _16);
		zephir_check_temp_parameter(_9);
		zephir_check_call_status();
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, outMongoCollection, "setmongoclient", NULL, 20, _17);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_BOOL(_9, 1);
		ZEPHIR_CALL_METHOD(NULL, outMongoCollection, "setnoappendquery", NULL, 21, _9);
		zephir_check_call_status();
		RETURN_CCTOR(outMongoCollection);
	} else {
		ZEPHIR_SINIT_VAR(_18);
		ZVAL_LONG(&_18, 501);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "failure", NULL, 22, &_18, rst);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * 云存储文件
 *
 * @param string fieldName
 *            上传表单字段的名称
 * @return array 返回上传文件成功后的object
 *        
 *         object结构如下:
 *         array(
 *         ["_id"] :
 *         MongoId(
 *        
 *         id =
 *         "537cc9b54896194b228b4581"
 *         )
 *         ["collection_id"] :
 *         NULL
 *         ["name"] :
 *         "b21c8701a18b87d624ac8e2d050828381f30fd11.jpg"
 *         ["type"] :
 *         "image/jpeg"
 *         ["tmp_name"] :
 *         "/tmp/phpeBS799"
 *         ["error"] :
 *         0
 *         ["size"] :
 *         350522
 *         ["mime"] :
 *         "image/jpeg; charset=binary"
 *         ["filename"] :
 *         "b21c8701a18b87d624ac8e2d050828381f30fd11.jpg"
 *         ["uploadDate"] :
 *         MongoDate(
 *        
 *         sec =
 *         1400687029
 *         usec =
 *         515000
 *         )
 *         ["length"] :
 *         350522
 *         ["chunkSize"] :
 *         262144
 *         ["md5"] :
 *         "3a736c4eed22030dde16df11fee263e7"
 *         )
 *        
 */
PHP_METHOD(My_Mongo_Collection, storeToGridFS) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *metadata = NULL;
	zval *fieldName_param = NULL, *metadata_param = NULL, *finfo, *mime = NULL, *id = NULL, *gridfsFile = NULL, *_FILES, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7;
	zval *fieldName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &fieldName_param, &metadata_param);

	if (unlikely(Z_TYPE_P(fieldName_param) != IS_STRING && Z_TYPE_P(fieldName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'fieldName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(fieldName_param) == IS_STRING)) {
		zephir_get_strval(fieldName, fieldName_param);
	} else {
		ZEPHIR_INIT_VAR(fieldName);
		ZVAL_EMPTY_STRING(fieldName);
	}
	if (!metadata_param) {
		ZEPHIR_INIT_VAR(metadata);
		array_init(metadata);
	} else {
	metadata = metadata_param;

	}


	if (!(Z_TYPE_P(metadata) == IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(metadata);
		array_init(metadata);
	}
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	if (!(zephir_array_isset(_FILES, fieldName))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "_FILES[fieldName]无效", "my/mongo/collection.zep", 1020);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_array_fetch(&_1, _FILES, fieldName, PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 1023 TSRMLS_CC);
	zephir_fast_array_merge(_0, &(metadata), &(_1) TSRMLS_CC);
	ZEPHIR_CPY_WRT(metadata, _0);
	ZEPHIR_INIT_VAR(finfo);
	object_init_ex(finfo, zephir_get_internal_ce(SS("finfo") TSRMLS_CC));
	if (zephir_has_constructor(finfo TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 1040);
		ZEPHIR_CALL_METHOD(NULL, finfo, "__construct", NULL, 0, _2);
		zephir_check_call_status();
	}
	zephir_array_fetch(&_3, _FILES, fieldName, PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 1025 TSRMLS_CC);
	zephir_array_fetch_string(&_4, _3, SL("tmp_name"), PH_NOISY | PH_READONLY, "my/mongo/collection.zep", 1025 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&mime, finfo, "file", NULL, 0, _4);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(mime)) {
		zephir_array_update_string(&metadata, SL("mime"), &mime, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initgridfs", NULL, 23);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_fs"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&id, _5, "storeupload", NULL, 0, fieldName, metadata);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_fs"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&gridfsFile, _6, "get", NULL, 0, id);
	zephir_check_call_status();
	if (!(zephir_is_instance_of(gridfsFile, SL("MongoGridFSFile") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "gridfsFile is not instanceof MongoGridFSFile", "my/mongo/collection.zep", 1034);
		return;
	}
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property(&_7, gridfsFile, SL("file"), PH_NOISY_CC);
	RETURN_CCTOR(_7);

}

/**
 * 存储二进制内容
 *
 * @param bytes bytes            
 * @param string filename            
 * @param array metadata            
 */
PHP_METHOD(My_Mongo_Collection, storeBytesToGridFS) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *metadata = NULL;
	zval *filename = NULL;
	zval *bytes, *filename_param = NULL, *metadata_param = NULL, *finfo, *mime = NULL, *id = NULL, *gridfsFile = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &bytes, &filename_param, &metadata_param);

	if (!filename_param) {
		ZEPHIR_INIT_VAR(filename);
		ZVAL_STRING(filename, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(filename_param) != IS_STRING && Z_TYPE_P(filename_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filename' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(filename_param) == IS_STRING)) {
		zephir_get_strval(filename, filename_param);
	} else {
		ZEPHIR_INIT_VAR(filename);
		ZVAL_EMPTY_STRING(filename);
	}
	}
	if (!metadata_param) {
		ZEPHIR_INIT_VAR(metadata);
		array_init(metadata);
	} else {
	metadata = metadata_param;

	}


	if (!(Z_TYPE_P(metadata) == IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(metadata);
		array_init(metadata);
	}
	if (!(ZEPHIR_IS_EMPTY(filename))) {
		zephir_array_update_string(&metadata, SL("filename"), &filename, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(finfo);
	object_init_ex(finfo, zephir_get_internal_ce(SS("finfo") TSRMLS_CC));
	if (zephir_has_constructor(finfo TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_LONG(_0, 1040);
		ZEPHIR_CALL_METHOD(NULL, finfo, "__construct", NULL, 0, _0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&mime, finfo, "buffer", NULL, 0, bytes);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(mime)) {
		zephir_array_update_string(&metadata, SL("mime"), &mime, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initgridfs", NULL, 23);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_fs"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&id, _1, "storebytes", NULL, 0, bytes, metadata);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_fs"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&gridfsFile, _2, "get", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, gridfsFile, SL("file"), PH_NOISY_CC);
	RETURN_CCTOR(_3);

}

/**
 * 获取指定ID的GridFSFile对象
 *
 * @param string id            
 * @return \MongoGridFSFile object
 */
PHP_METHOD(My_Mongo_Collection, getGridFsFileById) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);

	ZEPHIR_SEPARATE_PARAM(id);


	if (!(zephir_instance_of_ev(id, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(id);
		object_init_ex(id, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
		if (zephir_has_constructor(id TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, id, "__construct", NULL, 0, id);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initgridfs", NULL, 23);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_fs"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 根据查询条件获取指定数量的结果集
 *
 * @param array query            
 * @param number start            
 * @param number limit            
 * @return multitype:
 */
PHP_METHOD(My_Mongo_Collection, getGridFsFileBy) {

	int start, limit, ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *sort_param = NULL, *start_param = NULL, *limit_param = NULL, *fields_param = NULL, *cursor = NULL, *rst = NULL, *_0, *_1 = NULL;
	zval *query = NULL, *sort = NULL, *fields = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &query_param, &sort_param, &start_param, &limit_param, &fields_param);

	query = query_param;

	if (!sort_param) {
		ZEPHIR_INIT_VAR(sort);
		array_init(sort);
	} else {
	sort = sort_param;

	}
	if (!start_param) {
		start = 0;
	} else {
		start = zephir_get_intval(start_param);
	}
	if (!limit_param) {
		limit = 20;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
	fields = fields_param;

	}


	if (!(Z_TYPE_P(query) == IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(query);
		array_init(query);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initgridfs", NULL, 23);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_fs"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&cursor, _0, "find", NULL, 0, query, fields);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, cursor, "sort", NULL, 0, sort);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, start);
	ZEPHIR_CALL_METHOD(NULL, cursor, "skip", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, limit);
	ZEPHIR_CALL_METHOD(NULL, cursor, "limit", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&rst, "iterator_to_array", NULL, 14, cursor, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	RETURN_CCTOR(rst);

}

/**
 * 获取GridFS对象
 *
 * @return \MongoGridFS
 */
PHP_METHOD(My_Mongo_Collection, getGridFS) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initgridfs", NULL, 23);
	zephir_check_call_status();
	RETURN_MM_MEMBER(this_ptr, "_fs");

}

/**
 * 根据ID获取文件的信息
 *
 * @param string id            
 * @return array 文件信息数组
 */
PHP_METHOD(My_Mongo_Collection, getInfoFromGridFS) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id = NULL, *gridfsFile = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);

	ZEPHIR_SEPARATE_PARAM(id);


	if (!(zephir_instance_of_ev(id, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(id);
		object_init_ex(id, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
		if (zephir_has_constructor(id TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, id, "__construct", NULL, 0, id);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initgridfs", NULL, 23);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_fs"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&gridfsFile, _0, "get", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, gridfsFile, SL("file"), PH_NOISY_CC);
	RETURN_CCTOR(_1);

}

/**
 * 根据ID获取文件内容，二进制
 *
 * @param string id            
 * @return bytes
 */
PHP_METHOD(My_Mongo_Collection, getFileFromGridFS) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id = NULL, *gridfsFile = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);

	ZEPHIR_SEPARATE_PARAM(id);


	if (!(zephir_instance_of_ev(id, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(id);
		object_init_ex(id, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
		if (zephir_has_constructor(id TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, id, "__construct", NULL, 0, id);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initgridfs", NULL, 23);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_fs"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&gridfsFile, _0, "get", NULL, 0, id);
	zephir_check_call_status();
	if (zephir_is_instance_of(gridfsFile, SL("MongoGridFSFile") TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(gridfsFile, "getbytes", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		RETURN_MM_BOOL(0);
	}

}

/**
 * 删除陈旧的文件
 *
 * @param mixed id
 *            \MongoID or String
 * @return bool true or false
 */
PHP_METHOD(My_Mongo_Collection, removeFileFromGridFS) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *id = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);

	ZEPHIR_SEPARATE_PARAM(id);


	if (!(zephir_instance_of_ev(id, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(id);
		object_init_ex(id, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
		if (zephir_has_constructor(id TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, id, "__construct", NULL, 0, id);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initgridfs", NULL, 23);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_fs"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &id, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(_0, "remove", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(My_Mongo_Collection, array_unset_recursive) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	zend_bool remove;
	zval *arr_param = NULL, *fields_param = NULL, *remove_param = NULL, *key = NULL, *value = NULL, **_2, *_3 = NULL;
	zval *arr = NULL, *fields = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &arr_param, &fields_param, &remove_param);

	arr = arr_param;

	fields = fields_param;

	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	zephir_is_iterable(arr, &_1, &_0, 1, 0, "my/mongo/collection.zep", 1200);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (remove) {
			ZEPHIR_CALL_FUNCTION(&_3, "in_array", &_4, 4, key, fields, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
			if (zephir_is_true(_3)) {
				zephir_array_unset(&arr, key, PH_SEPARATE);
			} else {
				if (Z_TYPE_P(value) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "array_unset_recursive", &_5, 16, value, fields, (remove ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
				}
			}
		} else {
			ZEPHIR_CALL_FUNCTION(&_3, "in_array", &_4, 4, key, fields, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
			if (!(zephir_is_true(_3))) {
				zephir_array_unset(&arr, key, PH_SEPARATE);
			} else {
				if (Z_TYPE_P(value) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "array_unset_recursive", &_5, 16, value, fields, (remove ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
				}
			}
		}
	}
	RETURN_CTOR(arr);

}

/**
 * 打印最后一个错误信息
 */
PHP_METHOD(My_Mongo_Collection, debug) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *err = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_db"), PH_NOISY_CC);
	if (zephir_instance_of_ev(_0, zephir_get_internal_ce(SS("mongodb") TSRMLS_CC) TSRMLS_CC)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&err, _1, "lasterror", NULL, 0);
		zephir_check_call_status();
		RETURN_CCTOR(err);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 在析构函数中调用debug方法
 */
PHP_METHOD(My_Mongo_Collection, __destruct) {



}

