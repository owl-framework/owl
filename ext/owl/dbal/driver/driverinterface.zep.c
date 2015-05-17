
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_DriverInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\DBAL\\Driver, DriverInterface, owl, dbal_driver_driverinterface, owl_dbal_driver_driverinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Owl_DBAL_Driver_DriverInterface, isConnected);

ZEPHIR_DOC_METHOD(Owl_DBAL_Driver_DriverInterface, getNewPlatform);

ZEPHIR_DOC_METHOD(Owl_DBAL_Driver_DriverInterface, lastInsertId);

ZEPHIR_DOC_METHOD(Owl_DBAL_Driver_DriverInterface, prepare);

