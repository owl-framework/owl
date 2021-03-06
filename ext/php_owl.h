
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_OWL_H
#define PHP_OWL_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_OWL_NAME        "owl"
#define PHP_OWL_VERSION     "0.5"
#define PHP_OWL_EXTNAME     "owl"
#define PHP_OWL_AUTHOR      "Owl team and Contributors"
#define PHP_OWL_ZEPVERSION  "0.8.0a"
#define PHP_OWL_DESCRIPTION "Owl is an extreme fast PHP framework for building REST and MVC applications"



ZEND_BEGIN_MODULE_GLOBALS(owl)

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
	
ZEND_END_MODULE_GLOBALS(owl)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(owl)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(owl_globals_id, zend_owl_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (owl_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_owl_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(owl_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(owl_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def owl_globals
#define zend_zephir_globals_def zend_owl_globals

extern zend_module_entry owl_module_entry;
#define phpext_owl_ptr &owl_module_entry

#endif
