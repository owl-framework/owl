
extern zend_class_entry *owl_cache_driver_nativearray_ce;

ZEPHIR_INIT_CLASS(Owl_Cache_Driver_NativeArray);

PHP_METHOD(Owl_Cache_Driver_NativeArray, __construct);
PHP_METHOD(Owl_Cache_Driver_NativeArray, setInstance);
PHP_METHOD(Owl_Cache_Driver_NativeArray, getInstance);
PHP_METHOD(Owl_Cache_Driver_NativeArray, __destruct);
PHP_METHOD(Owl_Cache_Driver_NativeArray, save);
PHP_METHOD(Owl_Cache_Driver_NativeArray, delete);
PHP_METHOD(Owl_Cache_Driver_NativeArray, get);
PHP_METHOD(Owl_Cache_Driver_NativeArray, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_nativearray___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_nativearray_setinstance, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, instance, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_nativearray_save, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_nativearray_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_nativearray_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_cache_driver_nativearray_method_entry) {
	PHP_ME(Owl_Cache_Driver_NativeArray, __construct, arginfo_owl_cache_driver_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Cache_Driver_NativeArray, setInstance, arginfo_owl_cache_driver_nativearray_setinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_NativeArray, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_NativeArray, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Owl_Cache_Driver_NativeArray, save, arginfo_owl_cache_driver_nativearray_save, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_NativeArray, delete, arginfo_owl_cache_driver_nativearray_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_NativeArray, get, arginfo_owl_cache_driver_nativearray_get, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_NativeArray, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
