
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Owl_Service_Manager) {

	ZEPHIR_REGISTER_CLASS(Owl\\Service, Manager, owl, service_manager, owl_service_manager_method_entry, 0);

	zend_declare_property_null(owl_service_manager_ce, SL("instances"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_service_manager_ce, SL("services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Service_Manager, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *name_param = NULL, *definition, *_1, *_2 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = Z_TYPE_P(definition) == IS_OBJECT;
	if (!(_0)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_BOOL(_1, 1);
		ZEPHIR_CALL_FUNCTION(&_2, "is_callable", NULL, 28, definition, _1);
		zephir_check_call_status();
		_0 = zephir_is_true(_2);
	}
	if (_0) {
		zephir_update_property_array(this_ptr, SL("instances"), name, definition TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setservice", NULL, 0, name, definition);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Service_Manager, setService) {

	zval *name_param = NULL, *definition;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_array(this_ptr, SL("services"), name, definition TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Service_Manager, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getinstance", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Owl_Service_Manager, has) {

	zend_bool _1;
	zval *name_param = NULL, *_0, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instances"), PH_NOISY_CC);
	_1 = zephir_array_isset(_0, name);
	if (!(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("services"), PH_NOISY_CC);
		_1 = zephir_array_isset(_2, name);
	}
	RETURN_MM_BOOL(_1);

}

PHP_METHOD(Owl_Service_Manager, getInstance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *instance, *_0, *_1;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(instance);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instances"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&instance, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(instance);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, owl_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "Instance wasn't found by name: ", name);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 1, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "owl/Service/Manager.zep", 44 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Owl_Service_Manager, getService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *service, *_0, *_1;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(service);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("services"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&service, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(service);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, owl_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "Service wasn't found by name: ", name);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 1, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "owl/Service/Manager.zep", 55 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Owl_Service_Manager, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("services"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("instances"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

