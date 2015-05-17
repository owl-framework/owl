
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
	 * Latest Request
	 *
	 * @var \Owl\Http\RequestInterface
	 */
	zend_declare_property_null(owl_application_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	/**
	 * Count for dispatches
	 */
	zend_declare_property_long(owl_application_ce, SL("currentLoop"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Event\Manager
	 */
	zend_declare_property_null(owl_application_ce, SL("eventManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Handle parameters for exception catch
	 *
	 * @var array
	 */
	zend_declare_property_null(owl_application_ce, SL("exceptionHandlerParameters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Handle parameters for not found page
	 *
	 * @var array
	 */
	zend_declare_property_null(owl_application_ce, SL("errorHandlerParameters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(owl_application_ce TSRMLS_CC, 1, owl_applicationinterface_ce);
	return SUCCESS;

}

/**
 * Latest Request
 *
 * @var \Owl\Http\RequestInterface
 */
PHP_METHOD(Owl_Application, getRequest) {


	RETURN_MEMBER(this_ptr, "request");

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

/**
 * Handle parameters for exception catch
 *
 * @var array
 */
PHP_METHOD(Owl_Application, setExceptionHandlerParameters) {

	zval *exceptionHandlerParameters;

	zephir_fetch_params(0, 1, 0, &exceptionHandlerParameters);



	zephir_update_property_this(this_ptr, SL("exceptionHandlerParameters"), exceptionHandlerParameters TSRMLS_CC);

}

/**
 * Handle parameters for exception catch
 *
 * @var array
 */
PHP_METHOD(Owl_Application, getExceptionHandlerParameters) {


	RETURN_MEMBER(this_ptr, "exceptionHandlerParameters");

}

/**
 * Handle parameters for not found page
 *
 * @var array
 */
PHP_METHOD(Owl_Application, setErrorHandlerParameters) {

	zval *errorHandlerParameters;

	zephir_fetch_params(0, 1, 0, &errorHandlerParameters);



	zephir_update_property_this(this_ptr, SL("errorHandlerParameters"), errorHandlerParameters TSRMLS_CC);

}

/**
 * Handle parameters for not found page
 *
 * @var array
 */
PHP_METHOD(Owl_Application, getErrorHandlerParameters) {


	RETURN_MEMBER(this_ptr, "errorHandlerParameters");

}

PHP_METHOD(Owl_Application, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;
	zval *env = NULL;
	zval *di = NULL, *eventManager = NULL, *env_param = NULL, *_2;

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
	add_assoc_stringl_ex(_0, SS("controller"), SL("Index"), 1);
	add_assoc_stringl_ex(_0, SS("action"), SL("error"), 1);
	zephir_update_property_this(this_ptr, SL("errorHandlerParameters"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("module"), SL("Api"), 1);
	add_assoc_stringl_ex(_1, SS("controller"), SL("Index"), 1);
	add_assoc_stringl_ex(_1, SS("action"), SL("exception"), 1);
	zephir_update_property_this(this_ptr, SL("exceptionHandlerParameters"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("env"), env TSRMLS_CC);
	if (Z_TYPE_P(eventManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, owl_event_manager_ce);
		if (zephir_has_constructor(_2 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("eventManager"), _2 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("eventManager"), eventManager TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Dispatch the action
 */
PHP_METHOD(Owl_Application, dispatch) {

	zval *_13 = NULL;
	zend_class_entry *_6;
	zephir_fcall_cache_entry *_4 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, *callParameters = NULL, *response, *handlerClass, *controller, *result = NULL, *action, *e = NULL, *module, *_0 = NULL, *_1, *_2, *_3 = NULL, *_5 = NULL, *_7, *_8, *_9, *_10, *_11, *_12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &parameters, &callParameters, &response);

	if (!callParameters) {
		callParameters = ZEPHIR_GLOBAL(global_null);
	}


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("currentLoop") TSRMLS_CC));
	ZEPHIR_INIT_VAR(handlerClass);
	ZVAL_STRING(handlerClass, "\\RestApp\\", 1);
	ZEPHIR_OBS_VAR(module);
	if (zephir_array_isset_string_fetch(&module, parameters, SS("module"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VS(_0, module, "\\");
		zephir_concat_self(&handlerClass, _0 TSRMLS_CC);
	}
	zephir_array_fetch_string(&_1, parameters, SL("controller"), PH_NOISY | PH_READONLY, "owl/Application.zep", 102 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "Controller\\", _1, "Controller");
	zephir_concat_self(&handlerClass, _0 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("currentLoop"), PH_NOISY_CC);
	if (ZEPHIR_GT_LONG(_2, 3)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "World was crashed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 500);
		ZEPHIR_CALL_METHOD(NULL, response, "setcode", NULL, 0, _3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}

	/* try_start_1: */

		if (!(zephir_class_exists(handlerClass, 1 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, owl_exception_ce);
			ZEPHIR_INIT_LNVAR(_0);
			ZEPHIR_CONCAT_SVS(_0, "Class handler: '", handlerClass, "' is not exists");
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_4, 1, _0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_3, "owl/Application.zep", 113 TSRMLS_CC);
			goto try_end_1;

		}
		ZEPHIR_INIT_VAR(controller);
		zephir_fetch_safe_class(_5, handlerClass);
		_6 = zend_fetch_class(Z_STRVAL_P(_5), Z_STRLEN_P(_5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(controller, _6);
		if (zephir_has_constructor(controller TSRMLS_CC)) {
			_7 = zephir_fetch_nproperty_this(this_ptr, SL("request"), PH_NOISY_CC);
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, controller, "__construct", NULL, 0, _7, response, _8);
			zephir_check_call_status_or_jump(try_end_1);
		}
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "dispatch:afterInitialize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _9, "emit", NULL, 0, _3, this_ptr);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_array_fetch_string(&_10, parameters, SL("action"), PH_NOISY | PH_READONLY, "owl/Application.zep", 120 TSRMLS_CC);
		ZEPHIR_INIT_VAR(action);
		ZEPHIR_CONCAT_VS(action, _10, "Action");
		if (!((zephir_method_exists(controller, action TSRMLS_CC)  == SUCCESS))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, owl_exception_ce);
			ZEPHIR_INIT_VAR(_11);
			ZEPHIR_CONCAT_SVSVS(_11, "Action '", action, "' is not exists on '", handlerClass, "'");
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_4, 1, _11);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_3, "owl/Application.zep", 122 TSRMLS_CC);
			goto try_end_1;

		}
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "dispatch:afterAction", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _12, "emit", NULL, 0, _3, this_ptr);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(callParameters) == IS_NULL) {
			ZEPHIR_CALL_METHOD_ZVAL(&result, controller, action,  NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		} else {
			ZEPHIR_INIT_NVAR(result);
			ZEPHIR_INIT_VAR(_13);
			zephir_create_array(_13, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_13, controller);
			zephir_array_fast_append(_13, action);
			ZEPHIR_CALL_USER_FUNC_ARRAY(result, _13, callParameters);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, result);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_LONG(_3, 500);
			ZEPHIR_CALL_METHOD(NULL, response, "setcode", NULL, 0, _3);
			zephir_check_call_status();
			_7 = zephir_fetch_nproperty_this(this_ptr, SL("exceptionHandlerParameters"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_13);
			zephir_create_array(_13, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&_13, SL("exception"), &e, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", &_14, 2, _7, _13, response);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Handle Http Request
 */
PHP_METHOD(Owl_Application, handle) {

	zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response = NULL, *matchedRoute = NULL, *router = NULL, *_0, *_1 = NULL, *_3, *_4, *_5, *_6 = NULL, *_8, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &response);

	if (!response) {
		ZEPHIR_CPY_WRT(response, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(response);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "app:beforeHandle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _0, "emit", NULL, 0, _1, this_ptr);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (Z_TYPE_P(response) == IS_NULL) {
		ZEPHIR_INIT_NVAR(response);
		object_init_ex(response, owl_http_response_ce);
		ZEPHIR_CALL_METHOD(NULL, response, "__construct", &_2, 3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(_3, 0);
	zephir_update_property_this(this_ptr, SL("currentLoop"), _3 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dispatch:beforeExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _3, "emit", NULL, 0, _1, this_ptr);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&router, _4, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&matchedRoute, router, "matchrequest", NULL, 0, request);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dispatch:afterExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _5, "emit", NULL, 0, _1, this_ptr);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("request"), request TSRMLS_CC);
	if (zephir_is_true(matchedRoute)) {
		if (zephir_instance_of_ev(matchedRoute, owl_router_http_staticroute_ce TSRMLS_CC)) {
			ZEPHIR_OBS_VAR(_6);
			zephir_read_property(&_6, matchedRoute, SL("parameters"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_NULL(_1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", &_7, 0, _6, _1, response);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(_6);
			zephir_read_property(&_6, matchedRoute, SL("parameters"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(_8);
			zephir_read_property(&_8, matchedRoute, SL("uriParameters"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", &_7, 2, _6, _8, response);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 404);
		ZEPHIR_CALL_METHOD(NULL, response, "setcode", &_9, 4, _1);
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("errorHandlerParameters"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_NULL(_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", &_7, 2, _10, _1, response);
		zephir_check_call_status();
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app:afterHandle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _10, "emit", NULL, 0, _1, this_ptr);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETVAL_ZVAL(response, 1, 0);
	RETURN_MM();

}

