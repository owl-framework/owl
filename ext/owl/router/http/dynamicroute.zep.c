
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

	return SUCCESS;

}

PHP_METHOD(Owl_Router_Http_DynamicRoute, getPattern) {

	HashTable *_10;
	HashPosition _9;
	zend_bool _5;
	zval *_0, *pattern, *str = NULL, *len, *_1, *parts = NULL, *part = NULL, *params = NULL, _2 = zval_used_for_init, _3 = zval_used_for_init, *_4 = NULL, _6 = zval_used_for_init, _7 = zval_used_for_init, *_8 = NULL, **_11, *_12 = NULL, *_13, *_14, *_15, *_16, *_17, *_18 = NULL, *_19, *_20 = NULL;

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
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(len);
	ZVAL_LONG(len, zephir_fast_strlen_ev(_1));
	if (ZEPHIR_GT_LONG(len, 3)) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 0);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, 1);
		ZEPHIR_INIT_VAR(_4);
		zephir_substr(_4, str, 0 , 1 , 0);
		_5 = ZEPHIR_IS_STRING_IDENTICAL(_4, "/");
		if (_5) {
			ZEPHIR_SINIT_VAR(_6);
			ZVAL_LONG(&_6, ((zephir_get_numberval(len) - 1)));
			ZEPHIR_SINIT_VAR(_7);
			ZVAL_LONG(&_7, 1);
			ZEPHIR_INIT_VAR(_8);
			zephir_substr(_8, str, zephir_get_intval(&_6), 1 , 0);
			_5 = ZEPHIR_IS_STRING(_8, "/");
		}
		if (_5) {
			ZEPHIR_INIT_NVAR(parts);
			zephir_fast_explode_str(parts, SL("/"), str, LONG_MAX TSRMLS_CC);
			zephir_array_unset_long(&parts, 0, PH_SEPARATE);
			zephir_array_unset_long(&parts, zephir_fast_count_int(parts TSRMLS_CC), PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(_4);
	zephir_is_iterable(parts, &_10, &_9, 0, 0, "owl/Router/Http/DynamicRoute.zep", 52);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(_4, _10, _9);
		ZEPHIR_GET_HVALUE(part, _11);
		ZEPHIR_INIT_NVAR(params);
		zephir_fast_explode_str(params, SL(":"), part, LONG_MAX TSRMLS_CC);
		if (zephir_fast_count_int(params TSRMLS_CC) == 2) {
			ZEPHIR_OBS_NVAR(_12);
			zephir_array_fetch_long(&_12, params, 0, PH_NOISY, "owl/Router/Http/DynamicRoute.zep", 38 TSRMLS_CC);
			zephir_array_fetch_long(&_13, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 40 TSRMLS_CC);
			zephir_array_fetch_long(&_14, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 42 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 0);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_LONG(&_3, 1);
			ZEPHIR_INIT_NVAR(_8);
			zephir_substr(_8, _14, 0 , 1 , 0);
			_5 = ZEPHIR_IS_LONG(_8, '{');
			if (_5) {
				zephir_array_fetch_long(&_15, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 42 TSRMLS_CC);
				zephir_array_fetch_long(&_17, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 42 TSRMLS_CC);
				zephir_array_fetch_long(&_16, _15, (zephir_fast_strlen_ev(_17) - 1), PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 42 TSRMLS_CC);
				_5 = ZEPHIR_IS_LONG(_16, '}');
			}
			if (ZEPHIR_IS_EMPTY(_12)) {
				ZEPHIR_INIT_NVAR(_18);
				zephir_array_fetch_long(&_19, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 39 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_SVS(_20, "(?P<", _19, ">[0-9]++)");
				zephir_fast_str_replace(&_18, part, _20, str TSRMLS_CC);
				ZEPHIR_CPY_WRT(str, _18);
			} else if (ZEPHIR_IS_STRING(_13, "int")) {
				ZEPHIR_INIT_NVAR(_18);
				zephir_array_fetch_long(&_19, params, 0, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 41 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_SVS(_20, "(?P<", _19, ">[0-9]++)");
				zephir_fast_str_replace(&_18, part, _20, str TSRMLS_CC);
				ZEPHIR_CPY_WRT(str, _18);
			} else if (_5) {
				zephir_array_fetch_long(&_19, params, 1, PH_NOISY | PH_READONLY, "owl/Router/Http/DynamicRoute.zep", 43 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_LONG(&_6, 1);
				ZEPHIR_SINIT_NVAR(_7);
				ZVAL_LONG(&_7, -1);
				ZEPHIR_INIT_NVAR(str);
				zephir_substr(str, _19, 1 , -1 , 0);
				ZEPHIR_INIT_NVAR(_18);
				zephir_fast_str_replace(&_18, part, str, str TSRMLS_CC);
				ZEPHIR_CPY_WRT(str, _18);
			}
		}
	}
	ZEPHIR_INIT_LNVAR(_20);
	ZEPHIR_CONCAT_SVS(_20, "`^", str, "$`u");
	zephir_update_property_this(this_ptr, SL("pattern"), _20 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "pattern");

}

PHP_METHOD(Owl_Router_Http_DynamicRoute, match) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters;
	zval *uri_param = NULL, *_0 = NULL, *_1 = NULL, *_3, *_4;
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
	ZEPHIR_INIT_VAR(_3);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("parameters"), PH_NOISY_CC);
	zephir_fast_array_merge(_3, &(_4), &(parameters) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("parameters"), _3 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "parameters");

}

