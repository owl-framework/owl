
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(Owl_Application) {

	ZEPHIR_REGISTER_CLASS(Owl, Application, owl, application, owl_application_method_entry, 0);

	/**
	 * @var \Owl\Http\RequestInterface
	 */
	zend_declare_property_null(owl_application_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Http\Response
	 */
	zend_declare_property_null(owl_application_ce, SL("response"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Service\Manager
	 */
	zend_declare_property_null(owl_application_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Current env, see ENV_* constants
	 *
	 * @var string
	 */
	zend_declare_property_null(owl_application_ce, SL("env"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(owl_application_ce, SL("currentLoop"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_application_ce, SL("eventManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_application_ce, SL("exceptionHandlerParameters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(owl_application_ce TSRMLS_CC, 1, owl_applicationinterface_ce);
	return SUCCESS;

}

/**
 * @var \Owl\Http\RequestInterface
 */
PHP_METHOD(Owl_Application, getRequest) {


	RETURN_MEMBER(this_ptr, "request");

}

/**
 * @var \Owl\Http\Response
 */
PHP_METHOD(Owl_Application, getResponse) {


	RETURN_MEMBER(this_ptr, "response");

}

/**
 * @var \Owl\Service\Manager
 */
PHP_METHOD(Owl_Application, getDi) {


	RETURN_MEMBER(this_ptr, "di");

}

/**
 * Current env, see ENV_* constants
 *
 * @var string
 */
PHP_METHOD(Owl_Application, getEnv) {


	RETURN_MEMBER(this_ptr, "env");

}

PHP_METHOD(Owl_Application, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *env = NULL;
	zval *di = NULL, *eventManager = NULL, *env_param = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &di, &eventManager, &env_param);

	if (!di) {
		di = ZEPHIR_GLOBAL(global_null);
	}
	if (!eventManager) {
		eventManager = ZEPHIR_GLOBAL(global_null);
	}
	if (!env_param) {
		ZEPHIR_INIT_VAR(env);
		ZVAL_STRING(env, "production", 1);
	} else {
		zephir_get_strval(env, env_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("module"), SL("Api"), 1);
	add_assoc_stringl_ex(_0, SS("controller"), SL("Error"), 1);
	add_assoc_stringl_ex(_0, SS("action"), SL("exception"), 1);
	zephir_update_property_this(this_ptr, SL("exceptionHandlerParameters"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("env"), env TSRMLS_CC);
	if (Z_TYPE_P(eventManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, owl_event_manager_ce);
		if (zephir_has_constructor(_1 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("eventManager"), _1 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("eventManager"), eventManager TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Application, dispatch) {

	zval *_13;
	zend_class_entry *_7;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *parameters, *matchedRoute, *response, *handlerClass = NULL, *controller, *result = NULL, *action, *e = NULL, *module, *_1 = NULL, *_2, *_3, *_4 = NULL, *_6 = NULL, *_8, *_9, *_10, *_11, *_12, *_14, *_15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &parameters, &matchedRoute, &response);



	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("currentLoop") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SS(_0, "\\RestApp", "\\");
	ZEPHIR_CPY_WRT(handlerClass, _0);
	ZEPHIR_OBS_VAR(module);
	if (zephir_array_isset_string_fetch(&module, parameters, SS("module"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, module, "\\");
		zephir_concat_self(&handlerClass, _1 TSRMLS_CC);
	}
	zephir_array_fetch_string(&_2, parameters, SL("controller"), PH_NOISY | PH_READONLY, "owl/Application.zep", 70 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "Controller\\", _2, "Controller");
	zephir_concat_self(&handlerClass, _1 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("currentLoop"), PH_NOISY_CC);
	if (ZEPHIR_GT_LONG(_3, 3)) {
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "World was crashed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 500);
		ZEPHIR_CALL_METHOD(NULL, response, "setcode", NULL, _4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}

	/* try_start_1: */

		if (!(zephir_class_exists(handlerClass, 1 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_4);
			object_init_ex(_4, owl_exception_ce);
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SVS(_1, "Class handler: '", handlerClass, "' is not exists");
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_5, _1);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_4, "owl/Application.zep", 81 TSRMLS_CC);
			goto try_end_1;

		}
		ZEPHIR_INIT_VAR(controller);
		zephir_fetch_safe_class(_6, handlerClass);
		_7 = zend_fetch_class(Z_STRVAL_P(_6), Z_STRLEN_P(_6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(controller, _7);
		if (zephir_has_constructor(controller TSRMLS_CC)) {
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("request"), PH_NOISY_CC);
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, controller, "__construct", NULL, _8, response, _9);
			zephir_check_call_status_or_jump(try_end_1);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "dispatch:afterInitialize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _10, "emit", NULL, _4, this_ptr);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_array_fetch_string(&_11, parameters, SL("action"), PH_NOISY | PH_READONLY, "owl/Application.zep", 88 TSRMLS_CC);
		ZEPHIR_INIT_VAR(action);
		ZEPHIR_CONCAT_VS(action, _11, "Action");
		if (!((zephir_method_exists(controller, action TSRMLS_CC)  == SUCCESS))) {
			ZEPHIR_INIT_NVAR(_4);
			object_init_ex(_4, owl_exception_ce);
			ZEPHIR_INIT_VAR(_12);
			ZEPHIR_CONCAT_SVSVS(_12, "Action '", action, "' is not exists on '", handlerClass, "'");
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_5, _12);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_4, "owl/Application.zep", 90 TSRMLS_CC);
			goto try_end_1;

		}
		if (zephir_instance_of_ev(matchedRoute, owl_router_http_staticroute_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD_ZVAL(&result, controller, action,  NULL);
			zephir_check_call_status_or_jump(try_end_1);
		} else {
			ZEPHIR_INIT_NVAR(result);
			ZEPHIR_INIT_VAR(_13);
			zephir_create_array(_13, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_13, controller);
			zephir_array_fast_append(_13, action);
			ZEPHIR_OBS_VAR(_14);
			zephir_read_property(&_14, matchedRoute, SL("uriParameters"), PH_NOISY_CC);
			ZEPHIR_CALL_USER_FUNC_ARRAY(result, _13, _14);
			zephir_check_call_status_or_jump(try_end_1);
		}
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "dispatch:afterAction", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _15, "emit", NULL, _4, this_ptr);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, result);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, owl_exception_ce TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_LONG(_4, 500);
			ZEPHIR_CALL_METHOD(NULL, response, "setcode", NULL, _4);
			zephir_check_call_status();
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("exceptionHandlerParameters"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", &_16, _8, matchedRoute, response);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Handle Http Request
 */
PHP_METHOD(Owl_Application, handle) {

	zephir_fcall_cache_entry *_6 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response = NULL, *matchedRoute = NULL, *router = NULL, *_1, *_2 = NULL, *_3, *_4, *parameters = NULL, *_5, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &response);

	if (!response) {
		ZEPHIR_CPY_WRT(response, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(response);
	}


	if (Z_TYPE_P(response) == IS_NULL) {
		ZEPHIR_INIT_NVAR(response);
		object_init_ex(response, owl_http_response_ce);
		ZEPHIR_CALL_METHOD(NULL, response, "__construct", &_0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "dispatch:beforeExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _1, "emit", NULL, _2, this_ptr);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&router, _3, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&matchedRoute, router, "matchrequest", NULL, request);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "dispatch:afterExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _4, "emit", NULL, _2, this_ptr);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (zephir_is_true(matchedRoute)) {
		ZEPHIR_OBS_VAR(_5);
		zephir_read_property(&_5, matchedRoute, SL("parameters"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(parameters, _5);
		zephir_update_property_this(this_ptr, SL("request"), request TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", &_6, parameters, matchedRoute, response);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 404);
		ZEPHIR_CALL_METHOD(NULL, response, "setcode", &_7, _2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", &_6, parameters, matchedRoute, response);
		zephir_check_call_status();
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "app:afterHandle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _8, "emit", NULL, _2, this_ptr);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETVAL_ZVAL(response, 1, 0);
	RETURN_MM();

}

