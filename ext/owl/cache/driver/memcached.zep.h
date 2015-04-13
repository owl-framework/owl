
extern zend_class_entry *owl_cache_driver_memcached_ce;

ZEPHIR_INIT_CLASS(Owl_Cache_Driver_Memcached);

PHP_METHOD(Owl_Cache_Driver_Memcached, __construct);
PHP_METHOD(Owl_Cache_Driver_Memcached, setInstance);
PHP_METHOD(Owl_Cache_Driver_Memcached, getInstance);
PHP_METHOD(Owl_Cache_Driver_Memcached, __destruct);
PHP_METHOD(Owl_Cache_Driver_Memcached, save);
PHP_METHOD(Owl_Cache_Driver_Memcached, delete);
PHP_METHOD(Owl_Cache_Driver_Memcached, get);
PHP_METHOD(Owl_Cache_Driver_Memcached, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_memcached___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_memcached_setinstance, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, instance, Memcached, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_memcached_save, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifeTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_memcached_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_memcached_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_cache_driver_memcached_method_entry) {
	PHP_ME(Owl_Cache_Driver_Memcached, __construct, arginfo_owl_cache_driver_memcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Cache_Driver_Memcached, setInstance, arginfo_owl_cache_driver_memcached_setinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Memcached, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Memcached, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Owl_Cache_Driver_Memcached, save, arginfo_owl_cache_driver_memcached_save, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Memcached, delete, arginfo_owl_cache_driver_memcached_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Memcached, get, arginfo_owl_cache_driver_memcached_get, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Memcached, flush, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
