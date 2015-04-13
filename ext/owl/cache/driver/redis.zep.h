
extern zend_class_entry *owl_cache_driver_redis_ce;

ZEPHIR_INIT_CLASS(Owl_Cache_Driver_Redis);

PHP_METHOD(Owl_Cache_Driver_Redis, __construct);
PHP_METHOD(Owl_Cache_Driver_Redis, setInstance);
PHP_METHOD(Owl_Cache_Driver_Redis, getInstance);
PHP_METHOD(Owl_Cache_Driver_Redis, __destruct);
PHP_METHOD(Owl_Cache_Driver_Redis, save);
PHP_METHOD(Owl_Cache_Driver_Redis, delete);
PHP_METHOD(Owl_Cache_Driver_Redis, get);
PHP_METHOD(Owl_Cache_Driver_Redis, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_redis___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_redis_setinstance, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, instance, Redis, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_redis_save, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifeTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_redis_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_redis_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_cache_driver_redis_method_entry) {
	PHP_ME(Owl_Cache_Driver_Redis, __construct, arginfo_owl_cache_driver_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Cache_Driver_Redis, setInstance, arginfo_owl_cache_driver_redis_setinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Redis, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Redis, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Owl_Cache_Driver_Redis, save, arginfo_owl_cache_driver_redis_save, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Redis, delete, arginfo_owl_cache_driver_redis_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Redis, get, arginfo_owl_cache_driver_redis_get, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Cache_Driver_Redis, flush, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
