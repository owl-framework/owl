
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
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/time.h"

ZEPHIR_INIT_CLASS(Owl_Log_Logger) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Log, Logger, owl, log_logger, owl_log_abstractlogger_ce, owl_log_logger_method_entry, 0);

	/**
	 * Array of <Record> elements
	 */
	zend_declare_property_null(owl_log_logger_ce, SL("records"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Records limit to commit them to writers
	 */
	zend_declare_property_long(owl_log_logger_ce, SL("recordsInterval"), 1000, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Log writers
	 */
	zend_declare_property_null(owl_log_logger_ce, SL("writers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(owl_log_logger_ce TSRMLS_CC, 1, owl_log_loggerinterface_ce);
	return SUCCESS;

}

/**
 * Array of <Record> elements
 */
PHP_METHOD(Owl_Log_Logger, getRecords) {


	RETURN_MEMBER(this_ptr, "records");

}

/**
 * Records limit to commit them to writers
 */
PHP_METHOD(Owl_Log_Logger, getRecordsInterval) {


	RETURN_MEMBER(this_ptr, "recordsInterval");

}

/**
 * Records limit to commit them to writers
 */
PHP_METHOD(Owl_Log_Logger, setRecordsInterval) {

	zval *recordsInterval;

	zephir_fetch_params(0, 1, 0, &recordsInterval);



	zephir_update_property_this(this_ptr, SL("recordsInterval"), recordsInterval TSRMLS_CC);

}

/**
 * Log writers
 */
PHP_METHOD(Owl_Log_Logger, getWriters) {


	RETURN_MEMBER(this_ptr, "writers");

}

PHP_METHOD(Owl_Log_Logger, __construct) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3;
	HashPosition _2;
	zval *writers_param = NULL, *_0, *_1, *writerName = NULL, *writerDescription = NULL, **_4, *_5 = NULL;
	zval *writers = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &writers_param);

	if (!writers_param) {
		ZEPHIR_INIT_VAR(writers);
		array_init(writers);
	} else {
		zephir_get_arrval(writers, writers_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("writers"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("records"), _1 TSRMLS_CC);
	zephir_is_iterable(writers, &_3, &_2, 0, 0, "owl/Log/Logger.zep", 61);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(writerName, _3, _2);
		ZEPHIR_GET_HVALUE(writerDescription, _4);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "factorywriter", &_6, writerDescription);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("writers"), writerName, _5 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Log_Logger, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("records"), PH_NOISY_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "commit", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Create writer
 */
PHP_METHOD(Owl_Log_Logger, factoryWriter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_2;
	zval *writerDescription_param = NULL, *writer, *writerClass, *_0, *_1 = NULL, *_3;
	zval *writerDescription = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &writerDescription_param);

	if (!writerDescription_param) {
		ZEPHIR_INIT_VAR(writerDescription);
		array_init(writerDescription);
	} else {
		zephir_get_arrval(writerDescription, writerDescription_param);
	}


	if (!(zephir_array_isset_string(writerDescription, SS("class")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(owl_log_exception_invalidwriterexception_ce, "Writer options 'class' is not exists", "owl/Log/Logger.zep", 78);
		return;
	}
	zephir_array_fetch_string(&_0, writerDescription, SL("class"), PH_NOISY | PH_READONLY, "owl/Log/Logger.zep", 81 TSRMLS_CC);
	if (!(zephir_class_exists(_0, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(owl_log_exception_invalidwriterexception_ce, "Writer class is not exists", "owl/Log/Logger.zep", 82);
		return;
	}
	ZEPHIR_OBS_VAR(writerClass);
	zephir_array_fetch_string(&writerClass, writerDescription, SL("class"), PH_NOISY, "owl/Log/Logger.zep", 85 TSRMLS_CC);
	ZEPHIR_INIT_VAR(writer);
	zephir_fetch_safe_class(_1, writerClass);
	_2 = zend_fetch_class(Z_STRVAL_P(_1), Z_STRLEN_P(_1), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(writer, _2);
	if (zephir_has_constructor(writer TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, writer, "__construct", NULL);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(writerDescription, SS("levels"))) {
		zephir_array_fetch_string(&_3, writerDescription, SL("levels"), PH_NOISY | PH_READONLY, "owl/Log/Logger.zep", 89 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, writer, "setlevels", NULL, _3);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(writerDescription, SS("options"))) {
		zephir_array_fetch_string(&_3, writerDescription, SL("options"), PH_NOISY | PH_READONLY, "owl/Log/Logger.zep", 93 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, writer, "setoptions", NULL, _3);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(writerDescription, SS("formatter"))) {
		zephir_array_fetch_string(&_3, writerDescription, SL("formatter"), PH_NOISY | PH_READONLY, "owl/Log/Logger.zep", 97 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, writer, "setformatter", NULL, _3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(writer);

}

/**
 * Get writer
 */
PHP_METHOD(Owl_Log_Logger, getWriter) {

	zval *name_param = NULL, *_0, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("writers"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("writers"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, name, PH_NOISY | PH_READONLY, "owl/Log/Logger.zep", 109 TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Commit records
 */
PHP_METHOD(Owl_Log_Logger, commit) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *writer = NULL, *_0, **_3, *_4, *_5;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("writers"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "owl/Log/Logger.zep", 126);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(writer, _3);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("records"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, writer, "commit", NULL, _4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_this(this_ptr, SL("records"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_Logger, log) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message = NULL;
	zval *level, *message_param = NULL, *context_param = NULL, *_0, *_1, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, owl_log_record_ce);
	ZEPHIR_INIT_VAR(_1);
	zephir_microtime(_1, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_2, level, _1, message, context);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("records"), _0 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("records"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("recordsInterval"), PH_NOISY_CC);
	if (ZEPHIR_LE_LONG(_4, zephir_fast_count_int(_3 TSRMLS_CC))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "commit", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

