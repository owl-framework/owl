
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
#include "kernel/array.h"

/**
 * Return the class associated to the provided object handle
 *
 * @param zend_uint object handle
 *
 * @return char * class name
 */
const char *get_classname(zend_uint handle TSRMLS_DC)
{
    zend_objects_store *objects = &EG(objects_store);
    zend_object *object;
    zend_class_entry *class_entry;
    const char* class_name;

    class_name = "";

    if (objects->object_buckets[handle].valid) {
        struct _store_object *obj = &objects->object_buckets[handle].bucket.obj;
        object =  (zend_object * ) obj->object;

        class_entry = object->ce;
        class_name = class_entry->name;
    }

    return class_name;
}



ZEPHIR_INIT_CLASS(Owl_Debug_MemoryProfiler) {

	ZEPHIR_REGISTER_CLASS(Owl\\Debug, MemoryProfiler, owl, debug_memoryprofiler, owl_debug_memoryprofiler_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Debug_MemoryProfiler, getPlatformInfo) {

	zval *_0, *_1, *_2, *_3;
	int tmp = 0;
	zval *memoryInfo = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(memoryInfo);
	array_init(memoryInfo);

	ZEPHIR_INIT_NVAR(memoryInfo);
	array_init(memoryInfo);
	
			tmp = sizeof(zend_class_entry);
		
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, tmp);
	zephir_array_update_string(&memoryInfo, SL("zend_class_entry"), &_0, PH_COPY | PH_SEPARATE);
	
			tmp = sizeof(zend_object);
		
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, tmp);
	zephir_array_update_string(&memoryInfo, SL("zend_object"), &_1, PH_COPY | PH_SEPARATE);
	
			tmp = sizeof(zval);
		
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, tmp);
	zephir_array_update_string(&memoryInfo, SL("zval"), &_2, PH_COPY | PH_SEPARATE);
	
			tmp = sizeof(zvalue_value);
		
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, tmp);
	zephir_array_update_string(&memoryInfo, SL("zvalue_value"), &_3, PH_COPY | PH_SEPARATE);
	RETURN_CTOR(memoryInfo);

}

PHP_METHOD(Owl_Debug_MemoryProfiler, objectsList) {



}

