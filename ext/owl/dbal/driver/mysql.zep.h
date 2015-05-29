
extern zend_class_entry *owl_dbal_driver_mysql_ce;

ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_MySQL);

PHP_METHOD(Owl_DBAL_Driver_MySQL, setEventsManager);
PHP_METHOD(Owl_DBAL_Driver_MySQL, getEventsManager);
PHP_METHOD(Owl_DBAL_Driver_MySQL, __construct);
PHP_METHOD(Owl_DBAL_Driver_MySQL, isConnected);
PHP_METHOD(Owl_DBAL_Driver_MySQL, execute);
PHP_METHOD(Owl_DBAL_Driver_MySQL, connect);
PHP_METHOD(Owl_DBAL_Driver_MySQL, getNewPlatform);
PHP_METHOD(Owl_DBAL_Driver_MySQL, lastInsertId);
PHP_METHOD(Owl_DBAL_Driver_MySQL, prepare);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_mysql_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_mysql___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, driverOptions, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_mysql_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_mysql_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_dbal_driver_mysql_method_entry) {
	PHP_ME(Owl_DBAL_Driver_MySQL, setEventsManager, arginfo_owl_dbal_driver_mysql_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_MySQL, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_MySQL, __construct, arginfo_owl_dbal_driver_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_DBAL_Driver_MySQL, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_MySQL, execute, arginfo_owl_dbal_driver_mysql_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_MySQL, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_MySQL, getNewPlatform, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_MySQL, lastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_MySQL, prepare, arginfo_owl_dbal_driver_mysql_prepare, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
