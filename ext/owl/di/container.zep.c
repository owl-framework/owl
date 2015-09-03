
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Owl_Di_Container) {

	ZEPHIR_REGISTER_CLASS(Owl\\Di, Container, owl, di_container, owl_di_container_method_entry, 0);

	/**
	 * Service definitions
	 *
	 * @var array
	 */
	zend_declare_property_null(owl_di_container_ce, SL("services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Service object instances
	 *
	 * @var array
	 */
	zend_declare_property_null(owl_di_container_ce, SL("instances"), ZEND_ACC_PROTECTED TSRMLS_CC);

	owl_di_container_ce->create_object = zephir_init_properties_Owl_Di_Container;

	zend_class_implements(owl_di_container_ce TSRMLS_CC, 1, owl_di_containerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Owl_Di_Container, setService) {

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

PHP_METHOD(Owl_Di_Container, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *definition, *_0 = NULL, *_1 = NULL, *_2, *_3;
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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_CALL_FUNCTION(&_1, "is_callable", NULL, 15, definition, _0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		zephir_update_property_array(this_ptr, SL("instances"), name, definition TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(definition) == IS_OBJECT) {
		if (zephir_instance_of_ev(definition, owl_di_servicedefinitioninterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setservice", NULL, 0, name, definition);
			zephir_check_call_status();
		} else {
			zephir_update_property_array(this_ptr, SL("instances"), name, definition TSRMLS_CC);
		}
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(_0);
	object_init_ex(_0, owl_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	zephir_gettype(_2, name TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "It's not a registry to store it, type passed: ", _2);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 5, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "owl/Di/Container.zep", 44 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Owl_Di_Container, has) {

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

PHP_METHOD(Owl_Di_Container, get) {

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
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 5, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "owl/Di/Container.zep", 60 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Owl_Di_Container, getService) {

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
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 5, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "owl/Di/Container.zep", 71 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

static zend_object_value zephir_init_properties_Owl_Di_Container(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("instances"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("instances"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("services"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("services"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

