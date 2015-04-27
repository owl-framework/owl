
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Owl_Debug_Profiler) {

	ZEPHIR_REGISTER_CLASS(Owl\\Debug, Profiler, owl, debug_profiler, owl_debug_profiler_method_entry, 0);

	zend_declare_property_null(owl_debug_profiler_ce, SL("startTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Debug_Profiler, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_microtime(_0, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("startTime"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Debug_Profiler, logEvent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *event, *_0, *_1, *_2, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	ZEPHIR_INIT_VAR(_0);
	zephir_microtime(_0, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("startTime"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	sub_function(_2, _0, _1 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, " %.4F сек.", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "printf", &_4, &_3, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Debug_Profiler, listen) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_2;
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
	ZEPHIR_MM_RESTORE();

}

