
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"

ZEPHIR_INIT_CLASS(Owl_Router_Router) {

	ZEPHIR_REGISTER_CLASS(Owl\\Router, Router, owl, router_router, owl_router_router_method_entry, 0);

	zend_declare_property_string(owl_router_router_ce, SL("basePath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_router_router_ce, SL("routers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(owl_router_router_ce TSRMLS_CC, 1, owl_router_routerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Owl_Router_Router, getBasePath) {


	RETURN_MEMBER(this_ptr, "basePath");

}

PHP_METHOD(Owl_Router_Router, setBasePath) {

	zval *basePath;

	zephir_fetch_params(0, 1, 0, &basePath);



	zephir_update_property_this(this_ptr, SL("basePath"), basePath TSRMLS_CC);

}

PHP_METHOD(Owl_Router_Router, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _2;
	zval *parameters = NULL;
	zval *uri_param = NULL, *parameters_param = NULL, *method_param = NULL, *route, _0, *_1, _3, *_4;
	zval *uri = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &uri_param, &parameters_param, &method_param);

	zephir_get_strval(uri, uri_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
	parameters = parameters_param;

	}
	if (!method_param) {
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "GET", 1);
	} else {
		zephir_get_strval(method, method_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "{", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, uri, &_0, 0 );
	_2 = ZEPHIR_IS_FALSE_IDENTICAL(_1);
	if (_2) {
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, ":", 0);
		ZEPHIR_INIT_VAR(_4);
		zephir_fast_strpos(_4, uri, &_3, 0 );
		_2 = ZEPHIR_IS_FALSE_IDENTICAL(_4);
	}
	ZEPHIR_INIT_VAR(route);
	if (_2) {
		object_init_ex(route, owl_router_http_staticroute_ce);
		ZEPHIR_CALL_METHOD(NULL, route, "__construct", NULL, 27, uri);
		zephir_check_call_status();
	} else {
		object_init_ex(route, owl_router_http_dynamicroute_ce);
		ZEPHIR_CALL_METHOD(NULL, route, "__construct", NULL, 28, uri);
		zephir_check_call_status();
	}
	zephir_update_property_zval(route, SL("method"), method TSRMLS_CC);
	zephir_update_property_zval(route, SL("parameters"), parameters TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("routers"), route TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Router_Router, addRoute) {

	zval *route;

	zephir_fetch_params(0, 1, 0, &route);



	zephir_update_property_array_append(this_ptr, SL("routers"), route TSRMLS_CC);

}

PHP_METHOD(Owl_Router_Router, matchRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "match", NULL, 0, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Owl_Router_Router, match) {

	zend_bool _5, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *uri_param = NULL, *method_param = NULL, *router = NULL, *_0, **_3, *_4 = NULL, *_6 = NULL, *_8 = NULL;
	zval *uri = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri_param, &method_param);

	zephir_get_strval(uri, uri_param);
	if (!method_param) {
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "GET", 1);
	} else {
		zephir_get_strval(method, method_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("routers"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "owl/Router/Router.zep", 49);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(router, _3);
		ZEPHIR_CALL_METHOD(&_4, router, "match", NULL, 0, uri);
		zephir_check_call_status();
		_5 = zephir_is_true(_4);
		if (_5) {
			ZEPHIR_OBS_NVAR(_6);
			zephir_read_property(&_6, router, SL("method"), PH_NOISY_CC);
			_7 = ZEPHIR_IS_LONG(_6, 7);
			if (!(_7)) {
				ZEPHIR_OBS_NVAR(_8);
				zephir_read_property(&_8, router, SL("method"), PH_NOISY_CC);
				_7 = ZEPHIR_IS_EQUAL(_8, method);
			}
			_5 = _7;
		}
		if (_5) {
			RETURN_CCTOR(router);
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Owl_Router_Router, __construct) {


	if (EG(called_scope) == owl_router_router_ce) {
		zephir_init_properties(this_ptr TSRMLS_CC);
	}

}

static void zephir_init_properties(zval *this_ptr TSRMLS_DC) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("routers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

