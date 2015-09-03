
extern zend_class_entry *owl_dbal_driver_abstractpdoadapter_ce;

ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_AbstractPdoAdapter);

PHP_METHOD(Owl_DBAL_Driver_AbstractPdoAdapter, setEventsManager);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdoAdapter, getEventsManager);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdoAdapter, __construct);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdoAdapter, isConnected);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdoAdapter, execute);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdoAdapter, connect);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdoAdapter, getNewPlatform);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdoAdapter, lastInsertId);
PHP_METHOD(Owl_DBAL_Driver_AbstractPdoAdapter, prepare);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_abstractpdoadapter_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_abstractpdoadapter___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, driverOptions, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_abstractpdoadapter_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_abstractpdoadapter_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_dbal_driver_abstractpdoadapter_method_entry) {
	PHP_ME(Owl_DBAL_Driver_AbstractPdoAdapter, setEventsManager, arginfo_owl_dbal_driver_abstractpdoadapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdoAdapter, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdoAdapter, __construct, arginfo_owl_dbal_driver_abstractpdoadapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_DBAL_Driver_AbstractPdoAdapter, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdoAdapter, execute, arginfo_owl_dbal_driver_abstractpdoadapter_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdoAdapter, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdoAdapter, getNewPlatform, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdoAdapter, lastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_DBAL_Driver_AbstractPdoAdapter, prepare, arginfo_owl_dbal_driver_abstractpdoadapter_prepare, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
