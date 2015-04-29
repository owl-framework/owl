
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
#include "kernel/time.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Owl_Debug_Profiler) {

	ZEPHIR_REGISTER_CLASS(Owl\\Debug, Profiler, owl, debug_profiler, owl_debug_profiler_method_entry, 0);

	zend_declare_property_null(owl_debug_profiler_ce, SL("startTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_debug_profiler_ce, SL("lastTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

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

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL, *_8 = NULL, *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response, *html, *resp, *_1 = NULL, *_2, _3, _4 = zval_used_for_init, *_5 = NULL, *_7 = NULL, _9, *_10 = NULL, *_11 = NULL, *_12, *_13, *_14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_INIT_VAR(resp);
	object_init_ex(resp, owl_http_response_ce);
	ZEPHIR_CALL_METHOD(NULL, resp, "__construct", &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(html);
	ZVAL_STRING(html, "<html><head>", 1);
	zephir_concat_self_str(&html, SL("<link href=\"//owl-framework.github.io/assets/profiler/min.css\" media=\"all\" rel=\"stylesheet\">") TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</head><body>") TSRMLS_CC);
	zephir_concat_self_str(&html, SL("<div id='owl-debug-bar'>") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_microtime(_1, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("startTime"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	sub_function(&_3, _1, _2 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "%.4F ms", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", &_6, &_4, &_3);
	zephir_check_call_status();
	zephir_concat_self(&html, _5 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("\t") TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_7, "memory_get_peak_usage", &_8);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_STRING(&_4, "%.3f MB", 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_DOUBLE(&_9, zephir_safe_div_double_long(zephir_safe_div_zval_long(_7, 1024 TSRMLS_CC), (double) (1024) TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_10, "sprintf", &_6, &_4, &_9);
	zephir_check_call_status();
	zephir_concat_self(&html, _10 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("\t") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_11, response, "getcode", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_SV(_12, "HTTP Code ", _11);
	zephir_concat_self(&html, _12 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	zephir_concat_self_str(&html, SL("<pre><code>") TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CALL_METHOD(&_14, response, "getcontent", NULL);
	zephir_check_call_status();
	zephir_json_decode(_13, &(_13), _14, 0  TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, (128 | 256));
	zephir_json_encode(_1, &(_1), _13, zephir_get_intval(&_4)  TSRMLS_CC);
	zephir_concat_self(&html, _1 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</code></pre>") TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</body></html>") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, resp, "setcontent", &_15, html);
	zephir_check_call_status();
	RETURN_CCTOR(resp);

}

