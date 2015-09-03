
extern zend_class_entry *owl_dbal_driver_abstractpdo_ce;

ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_AbstractPdo);

PHP_METHOD(Owl_DBAL_Driver_AbstractPdo, setEventsManager);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdo, getEventsManager);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdo, __construct);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdo, isConnected);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdo, execute);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdo, connect);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdo, getNewPlatform);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdo, lastInsertId);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdo, prepare);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_abstractpdo_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_abstractpdo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, driverOptions, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_abstractpdo_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_abstractpdo_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_dbal_driver_abstractpdo_method_entry) {
	PHP_ME(Owl_DBAL_Driver_AbstractPdo, setEventsManager, arginfo_owl_dbal_driver_abstractpdo_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdo, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdo, __construct, arginfo_owl_dbal_driver_abstractpdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_DBAL_Driver_AbstractPdo, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdo, execute, arginfo_owl_dbal_driver_abstractpdo_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdo, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdo, getNewPlatform, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdo, lastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdo, prepare, arginfo_owl_dbal_driver_abstractpdo_prepare, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
