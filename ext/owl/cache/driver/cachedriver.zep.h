
extern zend_class_entry *owl_cache_driver_cachedriver_ce;

ZEPHIR_INIT_CLASS(Owl_Cache_Driver_CacheDriver);

PHP_METHOD(Owl_Cache_Driver_CacheDriver, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_cachedriver_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_cache_driver_cachedriver_method_entry) {
	PHP_ME(Owl_Cache_Driver_CacheDriver, exists, arginfo_owl_cache_driver_cachedriver_exists, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
