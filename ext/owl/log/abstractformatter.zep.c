
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


ZEPHIR_INIT_CLASS(Owl_Log_AbstractFormatter) {

	ZEPHIR_REGISTER_CLASS(Owl\\Log, AbstractFormatter, owl, log_abstractformatter, owl_log_abstractformatter_method_entry, 0);

	zend_class_implements(owl_log_abstractformatter_ce TSRMLS_CC, 1, owl_log_formatterinterface_ce);
	return SUCCESS;

}

/**
 * Interpolates context values into the message placeholders.
 *
 * @see http://www.php-fig.org/psr/psr-3/
 */
PHP_METHOD(Owl_Log_AbstractFormatter, interpolate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
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
		zephir_is_iterable(context, &_1, &_0, 0, 0, "owl/Log/AbstractFormatter.zep", 20);
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
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_4, message, replace);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(message);

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractFormatter, format) {

	zval *context = NULL;
	zval *message = NULL;
	double timestamp;
	zval *level, *timestamp_param = NULL, *message_param = NULL, *context_param = NULL;

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



}

