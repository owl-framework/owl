
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_PgSQL) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\DBAL\\Driver, PgSQL, owl, dbal_driver_pgsql, owl_dbal_driver_abstractpdo_ce, owl_dbal_driver_pgsql_method_entry, 0);

	zend_class_implements(owl_dbal_driver_pgsql_ce TSRMLS_CC, 1, owl_dbal_driver_driverinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Owl_DBAL_Driver_PgSQL, getNewPlatform) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, owl_dbal_platform_pgsql_ce);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

