
extern zend_class_entry *owl_dbal_driver_pgsql_ce;

ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_PgSQL);

PHP_METHOD(Owl_DBAL_Driver_PgSQL, setEventsManager);
PHP_METHOD(Owl_DBAL_Driver_PgSQL, getEventsManager);
PHP_METHOD(Owl_DBAL_Driver_PgSQL, __construct);
PHP_METHOD(Owl_DBAL_Driver_PgSQL, isConnected);
PHP_METHOD(Owl_DBAL_Driver_PgSQL, execute);
PHP_METHOD(Owl_DBAL_Driver_PgSQL, connect);
PHP_METHOD(Owl_DBAL_Driver_PgSQL, getNewPlatform);
PHP_METHOD(Owl_DBAL_Driver_PgSQL, lastInsertId);
PHP_METHOD(Owl_DBAL_Driver_PgSQL, prepare);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_pgsql_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_pgsql___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, driverOptions, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_pgsql_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_pgsql_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_dbal_driver_pgsql_method_entry) {
	PHP_ME(Owl_DBAL_Driver_PgSQL, setEventsManager, arginfo_owl_dbal_driver_pgsql_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_PgSQL, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_PgSQL, __construct, arginfo_owl_dbal_driver_pgsql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_DBAL_Driver_PgSQL, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_PgSQL, execute, arginfo_owl_dbal_driver_pgsql_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_PgSQL, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_PgSQL, getNewPlatform, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_PgSQL, lastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_PgSQL, prepare, arginfo_owl_dbal_driver_pgsql_prepare, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
