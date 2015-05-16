
namespace Owl\Debug;

%{
/**
 * Return the class associated to the provided object handle
 *
 * @param zend_uint object handle
 *
 * @return char * class name
 */
const char *get_classname(zend_uint handle)
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
}%

class MemoryProfiler
{
	public fn getPlatformInfo()
	{
		array memoryInfo = [];
		int tmp = 0;

		%{
			tmp = sizeof(zend_class_entry);
		}%

		let memoryInfo["zend_class_entry"] = tmp;

		%{
			tmp = sizeof(zend_object);
		}%

		let memoryInfo["zend_object"] = tmp;

		%{
			tmp = sizeof(zval);
		}%

		let memoryInfo["zval"] = tmp;

		%{
			tmp = sizeof(zvalue_value);
		}%

		let memoryInfo["zvalue_value"] = tmp;

		return memoryInfo;
	}

	public function objectsList()
	{
		int total_objects_buckets = 0, current_objects = 0;
		string className;
		array info = [], tmp = [], objectsTmp = [];

		let className = "";

		%{
			zend_objects_store *objects = &EG(objects_store);
			zend_uint i;
			zend_object * object;
			zend_class_entry * class_entry;

			total_objects_buckets = objects->top - 1;
		}%

		let info["total"] = total_objects_buckets;

		%{
		   for (i = 1; i < objects->top; i++) {
				if (objects->object_buckets[i].valid) {
					struct _store_object *obj = &objects->object_buckets[i].bucket.obj;

					Z_STRLEN_P(className) = get_classname(i);
					Z_TYPE_P(className) = IS_STRING;

					//php_stream_printf(stream, "  - Class %s, handle %d, refCount %d\n", get_classname(i), i, obj->refcount);

				}%

				//echo className;
				let tmp["name"] = "Test";
				let objectsTmp[] = tmp;

				%{
					current_objects++;
				}
			}
		}%

		let info["objects"] = objectsTmp;
		let info["current_objects"] = current_objects;

		return info;
	}
}
