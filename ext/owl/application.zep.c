
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
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

	zend_declare_class_constant_string(owl_application_ce, SL("ENV_PRODUCTION"), "production" TSRMLS_CC);

	zend_declare_class_constant_string(owl_application_ce, SL("ENV_DEVELOPMENT"), "development" TSRMLS_CC);

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
	zval *env = NULL;
	zval *di = NULL, *eventManager = NULL, *env_param = NULL, *_0;

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


	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("env"), env TSRMLS_CC);
	if (Z_TYPE_P(eventManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, owl_event_manager_ce);
		if (zephir_has_constructor(_0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("eventManager"), _0 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("eventManager"), eventManager TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Application, dispatch) {

	zval *_12;
	zend_class_entry *_8;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, *matchedRoute, *response, *handlerClass, *controller, *result = NULL, *action, *e = NULL, *_0, *_1, *_2, *_3, *_4 = NULL, *_5, *_7 = NULL, *_9, *_10, *_11, *_13, *_14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &parameters, &matchedRoute, &response);



	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("currentLoop") TSRMLS_CC));
	zephir_array_fetch_string(&_0, parameters, SL("module"), PH_NOISY | PH_READONLY, "owl/Application.zep", 61 TSRMLS_CC);
	zephir_array_fetch_string(&_1, parameters, SL("controller"), PH_NOISY | PH_READONLY, "owl/Application.zep", 61 TSRMLS_CC);
	ZEPHIR_INIT_VAR(handlerClass);
	ZEPHIR_CONCAT_SSVSVS(handlerClass, "\\RestApp", "\\", _0, "\\Controller\\", _1, "Controller");
	zephir_array_fetch_string(&_2, parameters, SL("action"), PH_NOISY | PH_READONLY, "owl/Application.zep", 62 TSRMLS_CC);
	ZEPHIR_INIT_VAR(action);
	ZEPHIR_CONCAT_VS(action, _2, "Action");
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
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_SVS(_5, "Class handler: '", handlerClass, "' is not exists");
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_4, "owl/Application.zep", 73 TSRMLS_CC);
			goto try_end_1;

		}
		ZEPHIR_INIT_VAR(controller);
		zephir_fetch_safe_class(_7, handlerClass);
		_8 = zend_fetch_class(Z_STRVAL_P(_7), Z_STRLEN_P(_7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(controller, _8);
		if (zephir_has_constructor(controller TSRMLS_CC)) {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("request"), PH_NOISY_CC);
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, controller, "__construct", NULL, _9, response, _10);
			zephir_check_call_status_or_jump(try_end_1);
		}
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "dispatch:afterInitialize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _11, "emit", NULL, _4, this_ptr);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_instance_of_ev(matchedRoute, owl_router_http_staticroute_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD_ZVAL(&result, controller, action,  NULL);
			zephir_check_call_status_or_jump(try_end_1);
		} else {
			ZEPHIR_INIT_NVAR(result);
			ZEPHIR_INIT_VAR(_12);
			array_init_size(_12, 3);
			zephir_array_fast_append(_12, controller);
			zephir_array_fast_append(_12, action);
			ZEPHIR_OBS_VAR(_13);
			zephir_read_property(&_13, matchedRoute, SL("uriParameters"), PH_NOISY_CC);
			ZEPHIR_CALL_USER_FUNC_ARRAY(result, _12, _13);
			zephir_check_call_status_or_jump(try_end_1);
		}
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "dispatch:afterAction", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _14, "emit", NULL, _4, this_ptr);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", NULL, parameters, matchedRoute, response);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Handle Http Request
 */
PHP_METHOD(Owl_Application, handle) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response = NULL, *matchedRoute = NULL, *router = NULL, *_0, *_1 = NULL, *_2, *_3, *parameters = NULL, *_4, *_6;

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
		if (zephir_has_constructor(response TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, response, "__construct", NULL);
			zephir_check_call_status();
		}
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "dispatch:beforeExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _0, "emit", NULL, _1, this_ptr);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&router, _2, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&matchedRoute, router, "matchrequest", NULL, request);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dispatch:afterExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _3, "emit", NULL, _1, this_ptr);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(matchedRoute)) {
		ZEPHIR_OBS_VAR(_4);
		zephir_read_property(&_4, matchedRoute, SL("parameters"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(parameters, _4);
		zephir_update_property_this(this_ptr, SL("request"), request TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", NULL, parameters, matchedRoute, response);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 404);
		ZEPHIR_CALL_METHOD(NULL, response, "setcode", &_5, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", NULL, parameters, matchedRoute, response);
		zephir_check_call_status();
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("eventManager"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app:afterHandle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _6, "emit", NULL, _1, this_ptr);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETVAL_ZVAL(response, 1, 0);
	RETURN_MM();

}

