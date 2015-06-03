
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_MY_H
#define PHP_MY_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_MY_NAME        "my"
#define PHP_MY_VERSION     "0.0.1"
#define PHP_MY_EXTNAME     "my"
#define PHP_MY_AUTHOR      "Young<shanghaiyangming@gmail.com>"
#define PHP_MY_ZEPVERSION  "0.6.3a"
#define PHP_MY_DESCRIPTION "My liberary compiled by zephir"

typedef struct _zephir_struct_my { 
	zend_bool mongo;
} zephir_struct_my;



ZEND_BEGIN_MODULE_GLOBALS(my)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
	zephir_struct_my my;


ZEND_END_MODULE_GLOBALS(my)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(my)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(my_globals_id, zend_my_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (my_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_my_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(my_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(my_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def my_globals
#define zend_zephir_globals_def zend_my_globals

extern zend_module_entry my_module_entry;
#define phpext_my_ptr &my_module_entry

#endif
