
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

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *owl_cache_driver_ce;
zend_class_entry *owl_log_writerinterface_ce;
zend_class_entry *owl_log_loggerinterface_ce;
zend_class_entry *owl_dbal_driver_driverinterface_ce;
zend_class_entry *owl_dbal_platform_platforminterface_ce;
zend_class_entry *owl_http_responseinterface_ce;
zend_class_entry *owl_log_formatterinterface_ce;
zend_class_entry *owl_mvc_controllerinterface_ce;
zend_class_entry *owl_applicationinterface_ce;
zend_class_entry *owl_di_containerinterface_ce;
zend_class_entry *owl_dispatcherinterface_ce;
zend_class_entry *owl_http_requestinterface_ce;
zend_class_entry *owl_router_routerinterface_ce;
zend_class_entry *owl_console_commandinterface_ce;
zend_class_entry *owl_session_managerinterface_ce;
zend_class_entry *owl_cache_driver_cachedriver_ce;
zend_class_entry *owl_log_abstractwriter_ce;
zend_class_entry *owl_exception_ce;
zend_class_entry *owl_router_route_ce;
zend_class_entry *owl_http_response_ce;
zend_class_entry *owl_log_abstractlogger_ce;
zend_class_entry *owl_mvc_controller_ce;
zend_class_entry *owl_std_arraybag_ce;
zend_class_entry *owl_std_collection_abstractcollection_ce;
zend_class_entry *owl_annotations_annotation_ce;
zend_class_entry *owl_annotations_classannotationsresult_ce;
zend_class_entry *owl_annotations_exception_ce;
zend_class_entry *owl_annotations_reader_ce;
zend_class_entry *owl_application_ce;
zend_class_entry *owl_bridge_lynx_rest_entitycontroller_ce;
zend_class_entry *owl_cache_driver_memcache_ce;
zend_class_entry *owl_cache_driver_memcached_ce;
zend_class_entry *owl_cache_driver_nativearray_ce;
zend_class_entry *owl_cache_driver_redis_ce;
zend_class_entry *owl_console_application_ce;
zend_class_entry *owl_dbal_connection_ce;
zend_class_entry *owl_dbal_driver_mysql_ce;
zend_class_entry *owl_dbal_driver_pdo_ce;
zend_class_entry *owl_dbal_driver_pgsql_ce;
zend_class_entry *owl_dbal_exception_ce;
zend_class_entry *owl_dbal_platform_mysql_ce;
zend_class_entry *owl_dbal_platform_pgsql_ce;
zend_class_entry *owl_debug_memoryprofiler_ce;
zend_class_entry *owl_debug_profiler_ce;
zend_class_entry *owl_di_container_ce;
zend_class_entry *owl_event_event_ce;
zend_class_entry *owl_event_manager_ce;
zend_class_entry *owl_http_headersbag_ce;
zend_class_entry *owl_http_request_ce;
zend_class_entry *owl_http_response_json_ce;
zend_class_entry *owl_log_exception_invalidformatterexception_ce;
zend_class_entry *owl_log_exception_invalidwriterexception_ce;
zend_class_entry *owl_log_formatter_json_ce;
zend_class_entry *owl_log_formatter_line_ce;
zend_class_entry *owl_log_logger_ce;
zend_class_entry *owl_log_record_ce;
zend_class_entry *owl_log_writer_devnull_ce;
zend_class_entry *owl_log_writer_echobrowser_ce;
zend_class_entry *owl_log_writer_file_ce;
zend_class_entry *owl_module_manager_ce;
zend_class_entry *owl_mvc_view_ce;
zend_class_entry *owl_mvc_view_engine_php_ce;
zend_class_entry *owl_router_http_dynamicroute_ce;
zend_class_entry *owl_router_http_staticroute_ce;
zend_class_entry *owl_router_router_ce;
zend_class_entry *owl_std_collection_arraycollection_ce;

ZEND_DECLARE_MODULE_GLOBALS(owl)

PHP_INI_BEGIN()
	
PHP_INI_END()

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
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Owl_Cache_Driver);
	ZEPHIR_INIT(Owl_Log_WriterInterface);
	ZEPHIR_INIT(Owl_Log_LoggerInterface);
	ZEPHIR_INIT(Owl_DBAL_Driver_DriverInterface);
	ZEPHIR_INIT(Owl_DBAL_Platform_PlatformInterface);
	ZEPHIR_INIT(Owl_Http_ResponseInterface);
	ZEPHIR_INIT(Owl_Log_FormatterInterface);
	ZEPHIR_INIT(Owl_Mvc_ControllerInterface);
	ZEPHIR_INIT(Owl_ApplicationInterface);
	ZEPHIR_INIT(Owl_Di_ContainerInterface);
	ZEPHIR_INIT(Owl_DispatcherInterface);
	ZEPHIR_INIT(Owl_Http_RequestInterface);
	ZEPHIR_INIT(Owl_Router_RouterInterface);
	ZEPHIR_INIT(Owl_Console_CommandInterface);
	ZEPHIR_INIT(Owl_Session_ManagerInterface);
	ZEPHIR_INIT(Owl_Cache_Driver_CacheDriver);
	ZEPHIR_INIT(Owl_Log_AbstractWriter);
	ZEPHIR_INIT(Owl_Exception);
	ZEPHIR_INIT(Owl_Router_Route);
	ZEPHIR_INIT(Owl_Http_Response);
	ZEPHIR_INIT(Owl_Log_AbstractLogger);
	ZEPHIR_INIT(Owl_Mvc_Controller);
	ZEPHIR_INIT(Owl_Std_ArrayBag);
	ZEPHIR_INIT(Owl_Std_Collection_AbstractCollection);
	ZEPHIR_INIT(Owl_Annotations_Annotation);
	ZEPHIR_INIT(Owl_Annotations_ClassAnnotationsResult);
	ZEPHIR_INIT(Owl_Annotations_Exception);
	ZEPHIR_INIT(Owl_Annotations_Reader);
	ZEPHIR_INIT(Owl_Application);
	ZEPHIR_INIT(Owl_Bridge_Lynx_Rest_EntityController);
	ZEPHIR_INIT(Owl_Cache_Driver_Memcache);
	ZEPHIR_INIT(Owl_Cache_Driver_Memcached);
	ZEPHIR_INIT(Owl_Cache_Driver_NativeArray);
	ZEPHIR_INIT(Owl_Cache_Driver_Redis);
	ZEPHIR_INIT(Owl_Console_Application);
	ZEPHIR_INIT(Owl_DBAL_Connection);
	ZEPHIR_INIT(Owl_DBAL_Driver_MySQL);
	ZEPHIR_INIT(Owl_DBAL_Driver_Pdo);
	ZEPHIR_INIT(Owl_DBAL_Driver_PgSQL);
	ZEPHIR_INIT(Owl_DBAL_Exception);
	ZEPHIR_INIT(Owl_DBAL_Platform_MySQL);
	ZEPHIR_INIT(Owl_DBAL_Platform_PgSQL);
	ZEPHIR_INIT(Owl_Debug_MemoryProfiler);
	ZEPHIR_INIT(Owl_Debug_Profiler);
	ZEPHIR_INIT(Owl_Di_Container);
	ZEPHIR_INIT(Owl_Event_Event);
	ZEPHIR_INIT(Owl_Event_Manager);
	ZEPHIR_INIT(Owl_Http_HeadersBag);
	ZEPHIR_INIT(Owl_Http_Request);
	ZEPHIR_INIT(Owl_Http_Response_Json);
	ZEPHIR_INIT(Owl_Log_Exception_InvalidFormatterException);
	ZEPHIR_INIT(Owl_Log_Exception_InvalidWriterException);
	ZEPHIR_INIT(Owl_Log_Formatter_Json);
	ZEPHIR_INIT(Owl_Log_Formatter_Line);
	ZEPHIR_INIT(Owl_Log_Logger);
	ZEPHIR_INIT(Owl_Log_Record);
	ZEPHIR_INIT(Owl_Log_Writer_DevNull);
	ZEPHIR_INIT(Owl_Log_Writer_EchoBrowser);
	ZEPHIR_INIT(Owl_Log_Writer_File);
	ZEPHIR_INIT(Owl_Module_Manager);
	ZEPHIR_INIT(Owl_Mvc_View);
	ZEPHIR_INIT(Owl_Mvc_View_Engine_Php);
	ZEPHIR_INIT(Owl_Router_Http_DynamicRoute);
	ZEPHIR_INIT(Owl_Router_Http_StaticRoute);
	ZEPHIR_INIT(Owl_Router_Router);
	ZEPHIR_INIT(Owl_Std_Collection_ArrayCollection);

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
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_owl_globals *owl_globals TSRMLS_DC)
{
	owl_globals->initialized = 0;

	/* Memory options */
	owl_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	owl_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	owl_globals->cache_enabled = 1;

	/* Recursive Lock */
	owl_globals->recursive_lock = 0;

	/* Static cache */
	memset(owl_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(owl)
{

	zend_owl_globals *owl_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(owl_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(owl_globals_ptr TSRMLS_CC);


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
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_OWL_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(owl)
{
	php_zephir_init_globals(owl_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(owl)
{

}


zend_function_entry php_owl_functions[] = {
ZEND_FE_END

};

zend_module_entry owl_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_OWL_EXTNAME,
	php_owl_functions,
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
