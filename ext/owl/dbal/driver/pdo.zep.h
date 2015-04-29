
extern zend_class_entry *owl_dbal_driver_pdo_ce;

ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_Pdo);

PHP_METHOD(Owl_DBAL_Driver_Pdo, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_pdo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_dbal_driver_pdo_method_entry) {
	PHP_ME(Owl_DBAL_Driver_Pdo, __construct, arginfo_owl_dbal_driver_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
