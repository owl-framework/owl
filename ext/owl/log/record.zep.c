
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
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Owl_Log_Record) {

	ZEPHIR_REGISTER_CLASS(Owl\\Log, Record, owl, log_record, owl_log_record_method_entry, 0);

	/**
	 * Record level
	 */
	zend_declare_property_null(owl_log_record_ce, SL("level"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Record timestamp
	 */
	zend_declare_property_null(owl_log_record_ce, SL("timestamp"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Record message
	 */
	zend_declare_property_null(owl_log_record_ce, SL("message"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Interpolates context values into the message placeholders.
 *
 * @see http://www.php-fig.org/psr/psr-3/
 */
PHP_METHOD(Owl_Log_Record, interpolate) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *replace, *key = NULL, *value = NULL, **_2, *_3 = NULL;
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


	if (zephir_fast_count_int(context TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(replace);
		array_init(replace);
		zephir_is_iterable(context, &_1, &_0, 0, 0, "owl/Log/Record.zep", 35);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "{", key, "}");
			zephir_array_update_zval(&replace, _3, &value, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 25, message, replace);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(message);

}

/**
 * Create and interpolate record message
 */
PHP_METHOD(Owl_Log_Record, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message = NULL;
	double timestamp;
	zval *level, *timestamp_param = NULL, *message_param = NULL, *context_param = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &level, &timestamp_param, &message_param, &context_param);

	timestamp = zephir_get_doubleval(timestamp_param);
	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "interpolate", NULL, 0, message, context);
	zephir_check_call_status();
	zephir_get_strval(message, _0);
	zephir_update_property_this(this_ptr, SL("level"), level TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, timestamp);
	zephir_update_property_this(this_ptr, SL("timestamp"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("message"), message TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

