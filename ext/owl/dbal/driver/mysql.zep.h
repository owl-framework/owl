
extern zend_class_entry *owl_dbal_driver_mysql_ce;

ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_MySQL);

PHP_METHOD(Owl_DBAL_Driver_MySQL, getNewPlatform);

ZEPHIR_INIT_FUNCS(owl_dbal_driver_mysql_method_entry) {
	PHP_ME(Owl_DBAL_Driver_MySQL, getNewPlatform, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
