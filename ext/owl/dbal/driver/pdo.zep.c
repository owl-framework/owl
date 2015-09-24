
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
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Owl_DBAL_Driver_Pdo) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\DBAL\\Driver, Pdo, owl, dbal_driver_pdo, php_pdo_get_dbh_ce(), owl_dbal_driver_pdo_method_entry, 0);

	zend_declare_class_constant_long(owl_dbal_driver_pdo_ce, SL("PARAM_EXPRESSION"), 10 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_DBAL_Driver_Pdo, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *dsn_param = NULL, *username = NULL, *password = NULL, *options_param = NULL, *_0 = NULL, *_1 = NULL;
	zval *dsn = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &dsn_param, &username, &password, &options_param);

	if (unlikely(Z_TYPE_P(dsn_param) != IS_STRING && Z_TYPE_P(dsn_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dsn' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(dsn_param) == IS_STRING)) {
		zephir_get_strval(dsn, dsn_param);
	} else {
		ZEPHIR_INIT_VAR(dsn);
		ZVAL_EMPTY_STRING(dsn);
	}
	if (!username) {
		username = ZEPHIR_GLOBAL(global_null);
	}
	if (!password) {
		password = ZEPHIR_GLOBAL(global_null);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, owl_dbal_driver_pdo_ce, this_ptr, "__construct", NULL, 0, dsn, username, password, options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 3);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setattribute", NULL, 0, _0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 19);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setattribute", NULL, 0, _0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

