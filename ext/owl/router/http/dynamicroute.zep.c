
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

	zend_bool _12;
	int _7;
	HashTable *_5;
	HashPosition _4;
	zval *_0, *pattern, *str = NULL, *len, *parts = NULL, *part = NULL, *params = NULL, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL, **_6, *_8 = NULL, *_9, *_10, *_11 = NULL, *_13, *_14, *_15, *_16 = NULL, *_17, *_18 = NULL, _19 = zval_used_for_init, _20 = zval_used_for_init;

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
	zephir_is_iterable(parts, &_5, &_4, 0, 0, "owl/Router/Http/DynamicRoute.zep", 60);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(_3, _5, _4);
		ZEPHIR_GET_HVALUE(part, _6);
		ZEPHIR_INIT_NVAR(params);
		zephir_fast_explode_str(params, SL(":"), part, LONG_MAX TSRMLS_CC);
		do {
			_7 = (zephir_fast_count_int(params TSRMLS_CC));
			if (_7 == 2) {
				ZEPHIR_OBS_NVAR(_8);
				zephir_array_fetch_long(&_8, params, 0, PH_NOISY, "owl/Router/Http/DynamicRoute.zep", 45 TSRMLS_CC);
				zephir_array_fetch_long(&_9, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 47 TSRMLS_CC);
				zephir_array_fetch_long(&_10, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 49 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, 0);
				ZEPHIR_SINIT_NVAR(_2);
				ZVAL_LONG(&_2, 1);
				ZEPHIR_INIT_NVAR(_11);
				zephir_substr(_11, _10, 0 , 1 , 0);
				_12 = ZEPHIR_IS_LONG(_11, '{');
				if (_12) {
					zephir_array_fetch_long(&_13, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 49 TSRMLS_CC);
					zephir_array_fetch_long(&_15, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 49 TSRMLS_CC);
					zephir_array_fetch_long(&_14, _13, (zephir_fast_strlen_ev(_15) - 1), PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 49 TSRMLS_CC);
					_12 = ZEPHIR_IS_LONG(_14, '}');
				}
				if (ZEPHIR_IS_EMPTY(_8)) {
					ZEPHIR_INIT_NVAR(_16);
					zephir_array_fetch_long(&_17, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 46 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_18);
					ZEPHIR_CONCAT_SVS(_18, "(?P<", _17, ">[0-9]++)");
					zephir_fast_str_replace(&_16, part, _18, str TSRMLS_CC);
					ZEPHIR_CPY_WRT(str, _16);
				} else if (ZEPHIR_IS_STRING(_9, "int")) {
					ZEPHIR_INIT_NVAR(_16);
					zephir_array_fetch_long(&_17, params, 0, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 48 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_18);
					ZEPHIR_CONCAT_SVS(_18, "(?P<", _17, ">[0-9]++)");
					zephir_fast_str_replace(&_16, part, _18, str TSRMLS_CC);
					ZEPHIR_CPY_WRT(str, _16);
				} else if (_12) {
					zephir_array_fetch_long(&_17, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 50 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_19);
					ZVAL_LONG(&_19, 1);
					ZEPHIR_SINIT_NVAR(_20);
					ZVAL_LONG(&_20, -1);
					ZEPHIR_INIT_NVAR(str);
					zephir_substr(str, _17, 1 , -1 , 0);
					ZEPHIR_INIT_NVAR(_16);
					zephir_fast_str_replace(&_16, part, str, str TSRMLS_CC);
					ZEPHIR_CPY_WRT(str, _16);
				}
				break;
			}
			if (_7 == 1) {
				break;
			}
		} while(0);

	}
	ZEPHIR_INIT_LNVAR(_18);
	ZEPHIR_CONCAT_SVS(_18, "`^", str, "$`u");
	zephir_update_property_this(this_ptr, SL("pattern"), _18 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "pattern");

}

PHP_METHOD(Owl_Router_Http_DynamicRoute, match) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters;
	zval *uri_param = NULL, *_0 = NULL, *_1 = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);
	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpattern", NULL);
	zephir_check_call_status();
	Z_SET_ISREF_P(parameters);
	ZEPHIR_CALL_FUNCTION(&_1, "preg_match", &_2, _0, uri, parameters);
	Z_UNSET_ISREF_P(parameters);
	zephir_check_call_status();
	if (!zephir_is_true(_1)) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_unset_long(&parameters, 0, PH_SEPARATE);
	zephir_array_unset_long(&parameters, (zephir_fast_count_int(parameters TSRMLS_CC) - 1), PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("uriParameters"), parameters TSRMLS_CC);
	RETURN_CTOR(parameters);

}

