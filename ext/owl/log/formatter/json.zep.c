
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Owl_Log_Formatter_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Log\\Formatter, Json, owl, log_formatter_json, owl_log_abstractformatter_ce, owl_log_formatter_json_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Log_Formatter_Json, format) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL, *_1;
	zval *message = NULL;
	double timestamp;
	zval *type, *timestamp_param = NULL, *message_param = NULL, *context_param = NULL, *_0 = NULL, *_2 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &type, &timestamp_param, &message_param, &context_param);

	timestamp = zephir_get_doubleval(timestamp_param);
	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "interpolate", NULL, message, context);
	zephir_check_call_status();
	zephir_get_strval(message, _0);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_2, owl_log_logger_ce, "getleveltitle", &_3, type);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("type"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("message"), &message, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_DOUBLE(_4, timestamp);
	zephir_array_update_string(&_1, SL("timestamp"), &_4, PH_COPY | PH_SEPARATE);
	zephir_json_encode(return_value, &(return_value), _1, 0  TSRMLS_CC);
	RETURN_MM();

}

