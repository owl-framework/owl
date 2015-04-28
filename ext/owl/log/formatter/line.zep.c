
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
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Owl_Log_Formatter_Line) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Log\\Formatter, Line, owl, log_formatter_line, owl_log_abstractformatter_ce, owl_log_formatter_line_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Log_Formatter_Line, format) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message = NULL;
	double timestamp;
	zval *type, *timestamp_param = NULL, *message_param = NULL, *context_param = NULL, *_0 = NULL, *_1 = NULL, _3, _4, *_5 = NULL;

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
	ZEPHIR_CALL_CE_STATIC(&_1, owl_log_logger_ce, "getleveltitle", &_2, type);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "D, d M Y H:i:s O", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_DOUBLE(&_4, timestamp);
	ZEPHIR_CALL_FUNCTION(&_5, "date", NULL, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVSV(return_value, _1, ":", _5, ":", message);
	RETURN_MM();

}

