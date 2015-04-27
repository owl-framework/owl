
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

PHP_METHOD(Owl_Debug_Profiler, show) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zval *html, *_0, *_1, _2, _3 = zval_used_for_init, *_4 = NULL, *_6 = NULL, _8, *_9 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(html);
	ZVAL_STRING(html, "<style>", 1);
	zephir_concat_self_str(&html, SL("#owl-debug-bar {width: 100%;height: 40px;line-height: 40px;border-bottom: 1px solid black;margin-bottom: 20px;background-color: #f8f8f8;}") TSRMLS_CC);
	zephir_concat_self_str(&html, SL("body {margin: 0; padding: 0;}") TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</style>") TSRMLS_CC);
	zephir_concat_self_str(&html, SL("<div id='owl-debug-bar'>") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_microtime(_0, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("startTime"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	sub_function(&_2, _0, _1 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "%.4F ms", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", &_5, &_3, &_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _4 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("\t") TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_6, "memory_get_peak_usage", &_7);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_STRING(&_3, "%.3f MB", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_DOUBLE(&_8, zephir_safe_div_double_long(zephir_safe_div_zval_long(_6, 1024 TSRMLS_CC), (double) (1024) TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_5, &_3, &_8);
	zephir_check_call_status();
	zephir_concat_self(&html, _9 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	zend_print_zval(html, 0);
	ZEPHIR_MM_RESTORE();

}

