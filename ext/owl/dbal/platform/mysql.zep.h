
extern zend_class_entry *owl_dbal_platform_mysql_ce;

ZEPHIR_INIT_CLASS(Owl_DBAL_Platform_MySQL);

PHP_METHOD(Owl_DBAL_Platform_MySQL, wrap);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_platform_mysql_wrap, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_dbal_platform_mysql_method_entry) {
	PHP_ME(Owl_DBAL_Platform_MySQL, wrap, arginfo_owl_dbal_platform_mysql_wrap, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
