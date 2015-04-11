
extern zend_class_entry *owl_cache_driver_ce;

ZEPHIR_INIT_CLASS(Owl_Cache_Driver);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_save, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifeTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_cache_driver_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_cache_driver_method_entry) {
	PHP_ABSTRACT_ME(Owl_Cache_Driver, getInstance, NULL)
	PHP_ABSTRACT_ME(Owl_Cache_Driver, save, arginfo_owl_cache_driver_save)
	PHP_ABSTRACT_ME(Owl_Cache_Driver, delete, arginfo_owl_cache_driver_delete)
	PHP_ABSTRACT_ME(Owl_Cache_Driver, get, arginfo_owl_cache_driver_get)
	PHP_ABSTRACT_ME(Owl_Cache_Driver, exists, arginfo_owl_cache_driver_exists)
	PHP_ABSTRACT_ME(Owl_Cache_Driver, flush, NULL)
  PHP_FE_END
};
