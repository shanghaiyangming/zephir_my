
extern zend_class_entry *my_mongo_collection_ce;

ZEPHIR_INIT_CLASS(My_Mongo_Collection);

PHP_METHOD(My_Mongo_Collection, setCollection);
PHP_METHOD(My_Mongo_Collection, getCollection);
PHP_METHOD(My_Mongo_Collection, setCollectionName);
PHP_METHOD(My_Mongo_Collection, getCollectionName);
PHP_METHOD(My_Mongo_Collection, setDatabaseName);
PHP_METHOD(My_Mongo_Collection, getDatabaseName);
PHP_METHOD(My_Mongo_Collection, setClusterName);
PHP_METHOD(My_Mongo_Collection, getClusterName);
PHP_METHOD(My_Mongo_Collection, setCollectionOptions);
PHP_METHOD(My_Mongo_Collection, getCollectionOptions);
PHP_METHOD(My_Mongo_Collection, setNoAppendQuery);
PHP_METHOD(My_Mongo_Collection, getNoAppendQuery);
PHP_METHOD(My_Mongo_Collection, __construct);
PHP_METHOD(My_Mongo_Collection, setMongoClient);
PHP_METHOD(My_Mongo_Collection, getMongoClient);
PHP_METHOD(My_Mongo_Collection, initCollection);
PHP_METHOD(My_Mongo_Collection, initDB);
PHP_METHOD(My_Mongo_Collection, initAdmin);
PHP_METHOD(My_Mongo_Collection, initBackup);
PHP_METHOD(My_Mongo_Collection, initMapreduce);
PHP_METHOD(My_Mongo_Collection, initGridFs);
PHP_METHOD(My_Mongo_Collection, appendQuery);
PHP_METHOD(My_Mongo_Collection, checkKeyExistInArray);
PHP_METHOD(My_Mongo_Collection, addSharedKeyToQuery);
PHP_METHOD(My_Mongo_Collection, search);
PHP_METHOD(My_Mongo_Collection, aggregate);
PHP_METHOD(My_Mongo_Collection, batchInsert);
PHP_METHOD(My_Mongo_Collection, count);
PHP_METHOD(My_Mongo_Collection, distinct);
PHP_METHOD(My_Mongo_Collection, drop);
PHP_METHOD(My_Mongo_Collection, physicalDrop);
PHP_METHOD(My_Mongo_Collection, ensureIndex);
PHP_METHOD(My_Mongo_Collection, createIndex);
PHP_METHOD(My_Mongo_Collection, checkIndexExist);
PHP_METHOD(My_Mongo_Collection, find);
PHP_METHOD(My_Mongo_Collection, findOne);
PHP_METHOD(My_Mongo_Collection, findAll);
PHP_METHOD(My_Mongo_Collection, findAndModify);
PHP_METHOD(My_Mongo_Collection, findAndModifyByCommand);
PHP_METHOD(My_Mongo_Collection, insertRef);
PHP_METHOD(My_Mongo_Collection, insert);
PHP_METHOD(My_Mongo_Collection, insertByFindAndModify);
PHP_METHOD(My_Mongo_Collection, remove);
PHP_METHOD(My_Mongo_Collection, physicalRemove);
PHP_METHOD(My_Mongo_Collection, physicalUpdate);
PHP_METHOD(My_Mongo_Collection, update);
PHP_METHOD(My_Mongo_Collection, save);
PHP_METHOD(My_Mongo_Collection, saveRef);
PHP_METHOD(My_Mongo_Collection, command);
PHP_METHOD(My_Mongo_Collection, failure);
PHP_METHOD(My_Mongo_Collection, mapReduce);
PHP_METHOD(My_Mongo_Collection, storeToGridFS);
PHP_METHOD(My_Mongo_Collection, storeBytesToGridFS);
PHP_METHOD(My_Mongo_Collection, getGridFsFileById);
PHP_METHOD(My_Mongo_Collection, getGridFsFileBy);
PHP_METHOD(My_Mongo_Collection, getGridFS);
PHP_METHOD(My_Mongo_Collection, getInfoFromGridFS);
PHP_METHOD(My_Mongo_Collection, getFileFromGridFS);
PHP_METHOD(My_Mongo_Collection, removeFileFromGridFS);
PHP_METHOD(My_Mongo_Collection, array_unset_recursive);
PHP_METHOD(My_Mongo_Collection, debug);
PHP_METHOD(My_Mongo_Collection, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_setcollection, 0, 0, 1)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_setcollectionname, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_setdatabasename, 0, 0, 1)
	ZEND_ARG_INFO(0, databaseName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_setclustername, 0, 0, 1)
	ZEND_ARG_INFO(0, clusterName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_setcollectionoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_setnoappendquery, 0, 0, 1)
	ZEND_ARG_INFO(0, noAppendQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, collectionName)
	ZEND_ARG_INFO(0, databaseName)
	ZEND_ARG_INFO(0, clusterName)
	ZEND_ARG_ARRAY_INFO(0, collectionOptions, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_setmongoclient, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, client, MongoClient, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_appendquery, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_checkkeyexistinarray, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_addsharedkeytoquery, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_search, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_aggregate, 0, 0, 1)
	ZEND_ARG_INFO(0, pipeline)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_batchinsert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, documents, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_count, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_distinct, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_ensureindex, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_createindex, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_checkindexexist, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_find, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_findone, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_findall, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
	ZEND_ARG_ARRAY_INFO(0, sort, 1)
	ZEND_ARG_INFO(0, skip)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_findandmodify, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, query, 0)
	ZEND_ARG_ARRAY_INFO(0, update, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_findandmodifybycommand, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, option, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_insertref, 0, 0, 1)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, a, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_insertbyfindandmodify, 0, 0, 1)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_remove, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, criteria, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_physicalremove, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, criteria, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_physicalupdate, 0, 0, 2)
	ZEND_ARG_INFO(0, criteria)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_update, 0, 0, 2)
	ZEND_ARG_INFO(0, criteria)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_save, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, a, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_saveref, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, a, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_command, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, command, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_failure, 0, 0, 2)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, msg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_mapreduce, 0, 0, 2)
	ZEND_ARG_INFO(0, out)
	ZEND_ARG_INFO(0, map)
	ZEND_ARG_INFO(0, reduce)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
	ZEND_ARG_INFO(0, finalize)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, scope)
	ZEND_ARG_INFO(0, sort)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_storetogridfs, 0, 0, 1)
	ZEND_ARG_INFO(0, fieldName)
	ZEND_ARG_ARRAY_INFO(0, metadata, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_storebytestogridfs, 0, 0, 1)
	ZEND_ARG_INFO(0, bytes)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_ARRAY_INFO(0, metadata, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_getgridfsfilebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_getgridfsfileby, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, query, 0)
	ZEND_ARG_ARRAY_INFO(0, sort, 1)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_getinfofromgridfs, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_getfilefromgridfs, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_removefilefromgridfs, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_my_mongo_collection_array_unset_recursive, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(my_mongo_collection_method_entry) {
	PHP_ME(My_Mongo_Collection, setCollection, arginfo_my_mongo_collection_setcollection, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getCollection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, setCollectionName, arginfo_my_mongo_collection_setcollectionname, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getCollectionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, setDatabaseName, arginfo_my_mongo_collection_setdatabasename, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getDatabaseName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, setClusterName, arginfo_my_mongo_collection_setclustername, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getClusterName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, setCollectionOptions, arginfo_my_mongo_collection_setcollectionoptions, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getCollectionOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, setNoAppendQuery, arginfo_my_mongo_collection_setnoappendquery, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getNoAppendQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, __construct, arginfo_my_mongo_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(My_Mongo_Collection, setMongoClient, arginfo_my_mongo_collection_setmongoclient, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getMongoClient, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, initCollection, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, initDB, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, initAdmin, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, initBackup, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, initMapreduce, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, initGridFs, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, appendQuery, arginfo_my_mongo_collection_appendquery, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, checkKeyExistInArray, arginfo_my_mongo_collection_checkkeyexistinarray, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, addSharedKeyToQuery, arginfo_my_mongo_collection_addsharedkeytoquery, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, search, arginfo_my_mongo_collection_search, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, aggregate, arginfo_my_mongo_collection_aggregate, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, batchInsert, arginfo_my_mongo_collection_batchinsert, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, count, arginfo_my_mongo_collection_count, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, distinct, arginfo_my_mongo_collection_distinct, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, drop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, physicalDrop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, ensureIndex, arginfo_my_mongo_collection_ensureindex, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, createIndex, arginfo_my_mongo_collection_createindex, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, checkIndexExist, arginfo_my_mongo_collection_checkindexexist, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, find, arginfo_my_mongo_collection_find, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, findOne, arginfo_my_mongo_collection_findone, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, findAll, arginfo_my_mongo_collection_findall, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, findAndModify, arginfo_my_mongo_collection_findandmodify, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, findAndModifyByCommand, arginfo_my_mongo_collection_findandmodifybycommand, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, insertRef, arginfo_my_mongo_collection_insertref, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, insert, arginfo_my_mongo_collection_insert, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, insertByFindAndModify, arginfo_my_mongo_collection_insertbyfindandmodify, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, remove, arginfo_my_mongo_collection_remove, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, physicalRemove, arginfo_my_mongo_collection_physicalremove, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, physicalUpdate, arginfo_my_mongo_collection_physicalupdate, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, update, arginfo_my_mongo_collection_update, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, save, arginfo_my_mongo_collection_save, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, saveRef, arginfo_my_mongo_collection_saveref, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, command, arginfo_my_mongo_collection_command, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, failure, arginfo_my_mongo_collection_failure, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, mapReduce, arginfo_my_mongo_collection_mapreduce, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, storeToGridFS, arginfo_my_mongo_collection_storetogridfs, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, storeBytesToGridFS, arginfo_my_mongo_collection_storebytestogridfs, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getGridFsFileById, arginfo_my_mongo_collection_getgridfsfilebyid, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getGridFsFileBy, arginfo_my_mongo_collection_getgridfsfileby, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getGridFS, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getInfoFromGridFS, arginfo_my_mongo_collection_getinfofromgridfs, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, getFileFromGridFS, arginfo_my_mongo_collection_getfilefromgridfs, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, removeFileFromGridFS, arginfo_my_mongo_collection_removefilefromgridfs, ZEND_ACC_PUBLIC)
	PHP_ME(My_Mongo_Collection, array_unset_recursive, arginfo_my_mongo_collection_array_unset_recursive, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, debug, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(My_Mongo_Collection, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
