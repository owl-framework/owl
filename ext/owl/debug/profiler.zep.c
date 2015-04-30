
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
#include "kernel/time.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Owl_Debug_Profiler) {

	ZEPHIR_REGISTER_CLASS(Owl\\Debug, Profiler, owl, debug_profiler, owl_debug_profiler_method_entry, 0);

	zend_declare_property_null(owl_debug_profiler_ce, SL("startTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_debug_profiler_ce, SL("lastTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(owl_debug_profiler_ce, SL("assetsUri"), "//owl-framework.github.io/assets/profiler/min.css", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Debug_Profiler, getAssetsUri) {


	RETURN_MEMBER(this_ptr, "assetsUri");

}

PHP_METHOD(Owl_Debug_Profiler, setAssetsUri) {

	zval *assetsUri;

	zephir_fetch_params(0, 1, 0, &assetsUri);



	zephir_update_property_this(this_ptr, SL("assetsUri"), assetsUri TSRMLS_CC);

}

PHP_METHOD(Owl_Debug_Profiler, __construct) {

	zval *time;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(time);
	zephir_microtime(time, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("startTime"), time TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("lastTime"), time TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Debug_Profiler, logEvent) {

	zval *event, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	ZEPHIR_INIT_VAR(_0);
	zephir_microtime(_0, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("lastTime"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Debug_Profiler, listen) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_2, *_3, *_4;
	zval *em, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &em);



	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "logEvent", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app:beforeHandle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, em, "listen", NULL, _1, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "logEvent", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app:afterHandle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, em, "listen", NULL, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "logEvent", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dispatch:afterExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, em, "listen", NULL, _1, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_4, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "logEvent", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dispatch:afterAction", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, em, "listen", NULL, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Debug_Profiler, setContent) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_8 = NULL, *_11 = NULL, *_21 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long tmp;
	zval *response, *html, *resp, *_1, *_2, *_3 = NULL, *_4, _5, _6 = zval_used_for_init, *_7 = NULL, *_9, *_10 = NULL, _12 = zval_used_for_init, *_13 = NULL, *_14, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18, *_19, *_20 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_INIT_VAR(resp);
	object_init_ex(resp, owl_http_response_ce);
	ZEPHIR_CALL_METHOD(NULL, resp, "__construct", &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(html);
	ZVAL_STRING(html, "<html><head>", 1);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("assetsUri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "<link href=\"", _1, "\" media=\"all\" rel=\"stylesheet\">");
	zephir_concat_self(&html, _2 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</head><body>") TSRMLS_CC);
	zephir_concat_self_str(&html, SL("<div id='owl-debug-bar'>") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_microtime(_3, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("startTime"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_5);
	sub_function(&_5, _3, _4 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "%.4Fms", 0);
	ZEPHIR_CALL_FUNCTION(&_7, "sprintf", &_8, &_6, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_SVS(_9, "<span class=\"label color-2\">", _7, "</span>");
	zephir_concat_self(&html, _9 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_10, "memory_get_peak_usage", &_11);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_STRING(&_6, "%.3fMB", 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_DOUBLE(&_12, zephir_safe_div_double_long(zephir_safe_div_zval_long(_10, 1024 TSRMLS_CC), (double) (1024) TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_13, "sprintf", &_8, &_6, &_12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_SVS(_14, "<span class=\"label color-3\">", _13, "</span>");
	zephir_concat_self(&html, _14 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_15, response, "getcode", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_16, response, "getcode", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_15, 200)) {
		tmp = 2;
	} else if (ZEPHIR_IS_LONG(_16, 500)) {
		tmp = 1;
	} else {
		tmp = 3;
	}
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, tmp);
	ZEPHIR_CALL_METHOD(&_17, response, "getcode", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_CONCAT_SVSVS(_18, "<span class=\"label color-", &_6, "\">", _17, "</span>");
	zephir_concat_self(&html, _18 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	if (zephir_instance_of_ev(response, owl_http_response_json_ce TSRMLS_CC)) {
		zephir_concat_self_str(&html, SL("<pre><code>") TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_VAR(_19);
		ZEPHIR_CALL_METHOD(&_20, response, "getcontent", NULL);
		zephir_check_call_status();
		zephir_json_decode(_19, &(_19), _20, 0  TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, (128 | 256));
		zephir_json_encode(_3, &(_3), _19, zephir_get_intval(&_12)  TSRMLS_CC);
		zephir_concat_self(&html, _3 TSRMLS_CC);
		zephir_concat_self_str(&html, SL("</code></pre>") TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_20, response, "getcontent", NULL);
		zephir_check_call_status();
		zephir_concat_self(&html, _20 TSRMLS_CC);
	}
	zephir_concat_self_str(&html, SL("</body></html>") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, resp, "setcontent", &_21, html);
	zephir_check_call_status();
	RETURN_CCTOR(resp);

}

