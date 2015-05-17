
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
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_DBAL_Platform_PgSQL) {

	ZEPHIR_REGISTER_CLASS(Owl\\DBAL\\Platform, PgSQL, owl, dbal_platform_pgsql, owl_dbal_platform_pgsql_method_entry, 0);

	zend_class_implements(owl_dbal_platform_pgsql_ce TSRMLS_CC, 1, owl_dbal_platform_platforminterface_ce);
	return SUCCESS;

}

PHP_METHOD(Owl_DBAL_Platform_PgSQL, wrap) {

	zval *id_param = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	RETURN_CTOR(id);

}

