
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
	zval *memoryInfo;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(memoryInfo);
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

	zval *_0, *_1, *_2;
	zval *info, *tmp, *objectsTmp;
	zval *className;
	int total_objects_buckets = 0, current_objects = 0;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(info);
	array_init(info);
	ZEPHIR_INIT_VAR(tmp);
	array_init(tmp);
	ZEPHIR_INIT_VAR(objectsTmp);
	array_init(objectsTmp);

	ZEPHIR_INIT_VAR(className);
	ZVAL_EMPTY_STRING(className);
	
			zend_objects_store *objects = &EG(objects_store);
			zend_uint i;

			total_objects_buckets = objects->top - 1;
		
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, total_objects_buckets);
	zephir_array_update_string(&info, SL("total"), &_0, PH_COPY | PH_SEPARATE);
	
		   for (i = 1; i < objects->top; i++) {
				if (objects->object_buckets[i].valid) {
					//struct _store_object *obj = &objects->object_buckets[i].bucket.obj;

					Z_STRLEN_P(className) = get_classname(i TSRMLS_CC);

					//php_stream_printf(stream, "  - Class %s, handle %d, refCount %d\n", get_classname(i), i, obj->refcount);

				
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Test", 1);
	zephir_array_update_string(&tmp, SL("name"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_append(&objectsTmp, tmp, PH_SEPARATE, "owl/Debug/MemoryProfiler.zep", 96);
	
					current_objects++;
				}
			}
		
	zephir_array_update_string(&info, SL("objects"), &objectsTmp, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, current_objects);
	zephir_array_update_string(&info, SL("current_objects"), &_2, PH_COPY | PH_SEPARATE);
	RETURN_CTOR(info);

}

