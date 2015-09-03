
extern zend_class_entry *owl_dbal_driver_pgsql_ce;

ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_PgSQL);

PHP_METHOD(Owl_DBAL_Driver_PgSQL, getNewPlatform);

ZEPHIR_INIT_FUNCS(owl_dbal_driver_pgsql_method_entry) {
	PHP_ME(Owl_DBAL_Driver_PgSQL, getNewPlatform, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
