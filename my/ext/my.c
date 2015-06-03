
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "my.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *my_mongo_client_ce;
zend_class_entry *my_mongo_collection_ce;
zend_class_entry *my_utils_lock_ce;
zend_class_entry *my_utils_registry_ce;

ZEND_DECLARE_MODULE_GLOBALS(my)

static PHP_MINIT_FUNCTION(my)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(My_Mongo_Client);
	ZEPHIR_INIT(My_Mongo_Collection);
	ZEPHIR_INIT(My_Utils_Lock);
	ZEPHIR_INIT(My_Utils_Registry);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(my)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_my_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zephir_globals->cache_enabled = 1;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;

	/* Static cache */
	memset(zephir_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	zephir_globals->my.mongo = 1;

}

static PHP_RINIT_FUNCTION(my)
{

	zend_my_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(my)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(my)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_MY_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_MY_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_MY_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_MY_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_MY_ZEPVERSION);
	php_info_print_table_end();

	php_info_print_table_start();
	php_info_print_table_header(2, "Directive", "Value");
	php_info_print_table_row(2, "my.utils.lock.memcached", "tcp://127.0.0.1:11211/?weight=20");
	php_info_print_table_end();

}

static PHP_GINIT_FUNCTION(my)
{
	php_zephir_init_globals(my_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(my)
{

}


zend_function_entry php_my_functions[] = {
ZEND_FE_END

};

zend_module_entry my_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_MY_EXTNAME,
	php_my_functions,
	PHP_MINIT(my),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(my),
#else
	NULL,
#endif
	PHP_RINIT(my),
	PHP_RSHUTDOWN(my),
	PHP_MINFO(my),
	PHP_MY_VERSION,
	ZEND_MODULE_GLOBALS(my),
	PHP_GINIT(my),
	PHP_GSHUTDOWN(my),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_MY
ZEND_GET_MODULE(my)
#endif
