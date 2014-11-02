
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_OWL_H
#define PHP_OWL_H 1

#include "kernel/globals.h"

#define PHP_OWL_NAME        "owl"
#define PHP_OWL_VERSION     "0.0.1"
#define PHP_OWL_EXTNAME     "owl"
#define PHP_OWL_AUTHOR      ""
#define PHP_OWL_ZEPVERSION  "0.5.7a"
#define PHP_OWL_DESCRIPTION ""



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
