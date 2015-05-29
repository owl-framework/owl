
extern zend_class_entry *owl_dbal_platform_platforminterface_ce;

ZEPHIR_INIT_CLASS(Owl_DBAL_Platform_PlatformInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_platform_platforminterface_wrap, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_dbal_platform_platforminterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_DBAL_Platform_PlatformInterface, wrap, arginfo_owl_dbal_platform_platforminterface_wrap)
	PHP_FE_END
};
