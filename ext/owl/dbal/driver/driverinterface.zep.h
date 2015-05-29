
extern zend_class_entry *owl_dbal_driver_driverinterface_ce;

ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_DriverInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dbal_driver_driverinterface_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_dbal_driver_driverinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_DBAL_Driver_DriverInterface, isConnected, NULL)
	PHP_ABSTRACT_ME(Owl_DBAL_Driver_DriverInterface, getNewPlatform, NULL)
	PHP_ABSTRACT_ME(Owl_DBAL_Driver_DriverInterface, lastInsertId, NULL)
	PHP_ABSTRACT_ME(Owl_DBAL_Driver_DriverInterface, prepare, arginfo_owl_dbal_driver_driverinterface_prepare)
	PHP_FE_END
};
