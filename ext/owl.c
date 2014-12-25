
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "owl.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *owl_router_routerinterface_ce;
zend_class_entry *owl_application_ce;
zend_class_entry *owl_exception_ce;
zend_class_entry *owl_http_request_ce;
zend_class_entry *owl_http_response_ce;
zend_class_entry *owl_module_manager_ce;
zend_class_entry *owl_mvc_controller_ce;
zend_class_entry *owl_router_router_ce;
zend_class_entry *owl_service_manager_ce;

ZEND_DECLARE_MODULE_GLOBALS(owl)

static PHP_MINIT_FUNCTION(owl)
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

	ZEPHIR_INIT(Owl_Router_RouterInterface);
	ZEPHIR_INIT(Owl_Application);
	ZEPHIR_INIT(Owl_Exception);
	ZEPHIR_INIT(Owl_Http_Request);
	ZEPHIR_INIT(Owl_Http_Response);
	ZEPHIR_INIT(Owl_Module_Manager);
	ZEPHIR_INIT(Owl_Mvc_Controller);
	ZEPHIR_INIT(Owl_Router_Router);
	ZEPHIR_INIT(Owl_Service_Manager);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(owl)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_owl_globals *zephir_globals TSRMLS_DC)
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


}

static PHP_RINIT_FUNCTION(owl)
{

	zend_owl_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(owl)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(owl)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_OWL_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_OWL_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_OWL_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_OWL_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_OWL_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(owl)
{
	php_zephir_init_globals(owl_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(owl)
{

}

zend_module_entry owl_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_OWL_EXTNAME,
	NULL,
	PHP_MINIT(owl),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(owl),
#else
	NULL,
#endif
	PHP_RINIT(owl),
	PHP_RSHUTDOWN(owl),
	PHP_MINFO(owl),
	PHP_OWL_VERSION,
	ZEND_MODULE_GLOBALS(owl),
	PHP_GINIT(owl),
	PHP_GSHUTDOWN(owl),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_OWL
ZEND_GET_MODULE(owl)
#endif
