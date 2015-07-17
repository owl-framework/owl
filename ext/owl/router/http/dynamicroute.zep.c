
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Owl_Router_Http_DynamicRoute) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Router\\Http, DynamicRoute, owl, router_http_dynamicroute, owl_router_route_ce, owl_router_http_dynamicroute_method_entry, 0);

	zend_declare_property_null(owl_router_http_dynamicroute_ce, SL("pattern"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_router_http_dynamicroute_ce, SL("uriParameters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Router_Http_DynamicRoute, __construct) {

	zval *uri_param = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	zephir_update_property_this(this_ptr, SL("uri"), uri TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Router_Http_DynamicRoute, getPattern) {

	zend_bool _14;
	int _8;
	HashTable *_5;
	HashPosition _4;
	zval *_0, *pattern, *str = NULL, *len, *parts = NULL, *part = NULL, *params = NULL, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL, **_6, *_7 = NULL, *_9 = NULL, *_10, *_11, *_12, _13 = zval_used_for_init, *_15, *_16, *_17, *_18 = NULL, *_19, *_20 = NULL, _21 = zval_used_for_init, _22 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(parts);
	array_init(parts);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pattern"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_MEMBER(this_ptr, "pattern");
	}
	ZEPHIR_OBS_VAR(pattern);
	zephir_read_property_this(&pattern, this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(str);
	zephir_read_property_this(&str, this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(len);
	ZVAL_LONG(len, zephir_fast_strlen_ev(str));
	if (ZEPHIR_GT_LONG(len, 3)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_INIT_VAR(_3);
		zephir_substr(_3, str, 0 , 1 , 0);
		if (ZEPHIR_IS_STRING_IDENTICAL(_3, "/")) {
			ZEPHIR_INIT_NVAR(parts);
			zephir_fast_explode_str(parts, SL("/"), str, LONG_MAX TSRMLS_CC);
			zephir_array_unset_long(&parts, 0, PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(_3);
	zephir_is_iterable(parts, &_5, &_4, 0, 0, "owl/Router/Http/DynamicRoute.zep", 66);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(_3, _5, _4);
		ZEPHIR_GET_HVALUE(part, _6);
		ZEPHIR_INIT_NVAR(params);
		zephir_fast_explode_str(params, SL(":"), part, LONG_MAX TSRMLS_CC);
		if (ZEPHIR_IS_STRING(part, ":params")) {
			ZEPHIR_INIT_NVAR(_7);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "(/.*)", 0);
			zephir_fast_str_replace(&_7, part, &_1, str TSRMLS_CC);
			ZEPHIR_CPY_WRT(str, _7);
		} else {
			do {
				_8 = (zephir_fast_count_int(params TSRMLS_CC));
				if (_8 == 2) {
					ZEPHIR_OBS_NVAR(_9);
					zephir_array_fetch_long(&_9, params, 0, PH_NOISY, "owl/Router/Http/DynamicRoute.zep", 48 TSRMLS_CC);
					zephir_array_fetch_long(&_10, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 50 TSRMLS_CC);
					zephir_array_fetch_long(&_11, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 52 TSRMLS_CC);
					zephir_array_fetch_long(&_12, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 54 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_2);
					ZVAL_LONG(&_2, 0);
					ZEPHIR_SINIT_NVAR(_13);
					ZVAL_LONG(&_13, 1);
					ZEPHIR_INIT_NVAR(_7);
					zephir_substr(_7, _12, 0 , 1 , 0);
					_14 = ZEPHIR_IS_LONG(_7, '{');
					if (_14) {
						zephir_array_fetch_long(&_15, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 54 TSRMLS_CC);
						zephir_array_fetch_long(&_17, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 54 TSRMLS_CC);
						zephir_array_fetch_long(&_16, _15, (zephir_fast_strlen_ev(_17) - 1), PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 54 TSRMLS_CC);
						_14 = ZEPHIR_IS_LONG(_16, '}');
					}
					if (ZEPHIR_IS_EMPTY(_9)) {
						ZEPHIR_INIT_NVAR(_18);
						zephir_array_fetch_long(&_19, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 49 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_20);
						ZEPHIR_CONCAT_SVS(_20, "(?P<", _19, ">[0-9]++)");
						zephir_fast_str_replace(&_18, part, _20, str TSRMLS_CC);
						ZEPHIR_CPY_WRT(str, _18);
					} else if (ZEPHIR_IS_STRING(_10, "int")) {
						ZEPHIR_INIT_NVAR(_18);
						zephir_array_fetch_long(&_19, params, 0, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 51 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_20);
						ZEPHIR_CONCAT_SVS(_20, "(?P<", _19, ">[0-9]++)");
						zephir_fast_str_replace(&_18, part, _20, str TSRMLS_CC);
						ZEPHIR_CPY_WRT(str, _18);
					} else if (ZEPHIR_IS_STRING(_11, "params")) {
						ZEPHIR_INIT_NVAR(_18);
						zephir_array_fetch_long(&_19, params, 0, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 53 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_20);
						ZEPHIR_CONCAT_VS(_20, _19, "(/.*)");
						zephir_fast_str_replace(&_18, part, _20, str TSRMLS_CC);
						ZEPHIR_CPY_WRT(str, _18);
					} else if (_14) {
						zephir_array_fetch_long(&_19, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 55 TSRMLS_CC);
						ZEPHIR_SINIT_NVAR(_21);
						ZVAL_LONG(&_21, 1);
						ZEPHIR_SINIT_NVAR(_22);
						ZVAL_LONG(&_22, -1);
						ZEPHIR_INIT_NVAR(str);
						zephir_substr(str, _19, 1 , -1 , 0);
						ZEPHIR_INIT_NVAR(_18);
						zephir_fast_str_replace(&_18, part, str, str TSRMLS_CC);
						ZEPHIR_CPY_WRT(str, _18);
					}
					break;
				}
				if (_8 == 1) {
					break;
				}
			} while(0);

		}
	}
	ZEPHIR_INIT_LNVAR(_20);
	ZEPHIR_CONCAT_SVS(_20, "`^", str, "$`u");
	zephir_update_property_this(this_ptr, SL("pattern"), _20 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "pattern");

}

PHP_METHOD(Owl_Router_Http_DynamicRoute, match) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters;
	zval *uri_param = NULL, *_0, *_1 = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);
	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpattern", NULL, 0);
	zephir_check_call_status();
	zephir_preg_match(_0, _1, uri, parameters, 0, 0 , 0  TSRMLS_CC);
	if (!zephir_is_true(_0)) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_unset_long(&parameters, 0, PH_SEPARATE);
	zephir_array_unset_long(&parameters, (zephir_fast_count_int(parameters TSRMLS_CC) - 1), PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("uriParameters"), parameters TSRMLS_CC);
	RETURN_CTOR(parameters);

}

