
extern zend_class_entry *owl_cache_driver_memcache_ce;

ZEPHIR_INIT_CLASS(Owl_Cache_Driver_Memcache);

PHP_METHOD(Owl_Cache_Driver_Memcache, __construct);
PHP_METHOD(Owl_Cache_Driver_Memcache, setInstance);
PHP_METHOD(Owl_Cache_Driver_Memcache, getInstance);
PHP_METHOD(Owl_Cache_Driver_Memcache, __destruct);
PHP_METHOD(Owl_Cache_Driver_Memcache, save);
PHP_METHOD(Owl_Cache_Driver_Memcache, delete);
PHP_METHOD(Owl_Cache_Driver_Memcache, get);
PHP_METHOD(Owl_Cache_Driver_Memcache, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_memcache___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_memcache_setinstance, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, instance, Memcache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_memcache_save, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifeTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_memcache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_memcache_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_cache_driver_memcache_method_entry) {
	PHP_ME(Owl_Cache_Driver_Memcache, __construct, arginfo_owl_cache_driver_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Cache_Driver_Memcache, setInstance, arginfo_owl_cache_driver_memcache_setinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Memcache, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Memcache, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Owl_Cache_Driver_Memcache, save, arginfo_owl_cache_driver_memcache_save, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Memcache, delete, arginfo_owl_cache_driver_memcache_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Memcache, get, arginfo_owl_cache_driver_memcache_get, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Memcache, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
