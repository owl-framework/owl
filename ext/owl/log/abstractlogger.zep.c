
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Owl_Log_AbstractLogger) {

	ZEPHIR_REGISTER_CLASS(Owl\\Log, AbstractLogger, owl, log_abstractlogger, owl_log_abstractlogger_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Log levers constants
	 */
	zend_declare_class_constant_long(owl_log_abstractlogger_ce, SL("LEVEL_ALERT"), 0x01 TSRMLS_CC);

	zend_declare_class_constant_long(owl_log_abstractlogger_ce, SL("LEVEL_CRITICAL"), 0x02 TSRMLS_CC);

	zend_declare_class_constant_long(owl_log_abstractlogger_ce, SL("LEVEL_EMERGENCY"), 0x03 TSRMLS_CC);

	zend_declare_class_constant_long(owl_log_abstractlogger_ce, SL("LEVEL_ERROR"), 0x04 TSRMLS_CC);

	zend_declare_class_constant_long(owl_log_abstractlogger_ce, SL("LEVEL_INFO"), 0x05 TSRMLS_CC);

	zend_declare_class_constant_long(owl_log_abstractlogger_ce, SL("LEVEL_DEBUG"), 0x06 TSRMLS_CC);

	zend_declare_class_constant_long(owl_log_abstractlogger_ce, SL("LEVEL_NOTICE"), 0x07 TSRMLS_CC);

	zend_declare_class_constant_long(owl_log_abstractlogger_ce, SL("LEVEL_WARNING"), 0x08 TSRMLS_CC);

	zend_class_implements(owl_log_abstractlogger_ce TSRMLS_CC, 1, owl_log_loggerinterface_ce);
	return SUCCESS;

}

/**
 * Get level title by internal level code
 */
PHP_METHOD(Owl_Log_AbstractLogger, getLevelTitle) {

	zval *level;

	zephir_fetch_params(0, 1, 0, &level);



	do {
		if (ZEPHIR_IS_LONG(level, 0x01)) {
			RETURN_STRING("alert", 1);
		}
		if (ZEPHIR_IS_LONG(level, 0x02)) {
			RETURN_STRING("critical", 1);
		}
		if (ZEPHIR_IS_LONG(level, 0x03)) {
			RETURN_STRING("emergency", 1);
		}
		if (ZEPHIR_IS_LONG(level, 0x04)) {
			RETURN_STRING("error", 1);
		}
		if (ZEPHIR_IS_LONG(level, 0x05)) {
			RETURN_STRING("info", 1);
		}
		if (ZEPHIR_IS_LONG(level, 0x06)) {
			RETURN_STRING("debug", 1);
		}
		if (ZEPHIR_IS_LONG(level, 0x07)) {
			RETURN_STRING("notice", 1);
		}
		if (ZEPHIR_IS_LONG(level, 0x08)) {
			RETURN_STRING("warning", 1);
		}
	} while(0);

	RETURN_STRING("unknown", 1);

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractLogger, emergency) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0x03);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractLogger, alert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0x01);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractLogger, critical) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0x02);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractLogger, error) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0x04);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractLogger, warning) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0x08);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractLogger, notice) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0x07);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractLogger, info) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0x05);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractLogger, debug) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0x06);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractLogger, log) {

}

