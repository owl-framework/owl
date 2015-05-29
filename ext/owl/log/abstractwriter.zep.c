
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/hash.h"

ZEPHIR_INIT_CLASS(Owl_Log_AbstractWriter) {

	ZEPHIR_REGISTER_CLASS(Owl\\Log, AbstractWriter, owl, log_abstractwriter, owl_log_abstractwriter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Writer log levels
	 */
	zend_declare_property_null(owl_log_abstractwriter_ce, SL("levels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Writer records
	 */
	zend_declare_property_null(owl_log_abstractwriter_ce, SL("records"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Writer options
	 */
	zend_declare_property_null(owl_log_abstractwriter_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Writer formatter
	 */
	zend_declare_property_null(owl_log_abstractwriter_ce, SL("formatter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Records limit to commit them to writers
	 */
	zend_declare_property_long(owl_log_abstractwriter_ce, SL("recordsInterval"), 1000, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(owl_log_abstractwriter_ce TSRMLS_CC, 1, owl_log_writerinterface_ce);
	return SUCCESS;

}

/**
 * Writer log levels
 */
PHP_METHOD(Owl_Log_AbstractWriter, getLevels) {


	RETURN_MEMBER(this_ptr, "levels");

}

/**
 * Writer log levels
 */
PHP_METHOD(Owl_Log_AbstractWriter, setLevels) {

	zval *levels;

	zephir_fetch_params(0, 1, 0, &levels);



	zephir_update_property_this(this_ptr, SL("levels"), levels TSRMLS_CC);

}

/**
 * Writer records
 */
PHP_METHOD(Owl_Log_AbstractWriter, getRecords) {


	RETURN_MEMBER(this_ptr, "records");

}

/**
 * Writer options
 */
PHP_METHOD(Owl_Log_AbstractWriter, getOptions) {


	RETURN_MEMBER(this_ptr, "options");

}

/**
 * Writer options
 */
PHP_METHOD(Owl_Log_AbstractWriter, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);

}

/**
 * Records limit to commit them to writers
 */
PHP_METHOD(Owl_Log_AbstractWriter, getRecordsInterval) {


	RETURN_MEMBER(this_ptr, "recordsInterval");

}

/**
 * Records limit to commit them to writers
 */
PHP_METHOD(Owl_Log_AbstractWriter, setRecordsInterval) {

	zval *recordsInterval;

	zephir_fetch_params(0, 1, 0, &recordsInterval);



	zephir_update_property_this(this_ptr, SL("recordsInterval"), recordsInterval TSRMLS_CC);

}

PHP_METHOD(Owl_Log_AbstractWriter, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("records"), PH_NOISY_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "push", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractWriter, setOption) {

	zval *option_param = NULL, *value;
	zval *option = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option_param, &value);

	zephir_get_strval(option, option_param);


	zephir_update_property_array(this_ptr, SL("options"), option, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractWriter, getOption) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, *_0, *_1, *_3, *_4;
	zval *option = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option_param);

	zephir_get_strval(option, option_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, option))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, owl_log_exception_invalidwriterexception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Option ", option, " is not exists");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 16, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "owl/Log/AbstractWriter.zep", 66 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	zephir_array_fetch(&_4, _3, option, PH_NOISY | PH_READONLY, "owl/Log/AbstractWriter.zep", 68 TSRMLS_CC);
	RETURN_CTOR(_4);

}

PHP_METHOD(Owl_Log_AbstractWriter, defaultFormatter) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, owl_log_formatter_line_ce);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractWriter, getFormatter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("formatter"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "defaultformatter", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("formatter"), _1 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "formatter");

}

PHP_METHOD(Owl_Log_AbstractWriter, setFormatter) {

	zend_class_entry *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *formatter, _1, *_2 = NULL, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &formatter);



	_0 = Z_TYPE_P(formatter) == IS_OBJECT;
	if (_0) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "\\Owl\\Log\\FormatterInterface", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "is_subclass_of", NULL, 17, formatter, &_1);
		zephir_check_call_status();
		_0 = zephir_is_true(_2);
	}
	if (_0) {
		zephir_update_property_this(this_ptr, SL("formatter"), formatter TSRMLS_CC);
	} else if (Z_TYPE_P(formatter) == IS_STRING) {
		if (!(zephir_class_exists(formatter, 1 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(owl_log_exception_invalidformatterexception_ce, "Formatter class is not exits", "owl/Log/AbstractWriter.zep", 94);
			return;
		}
		ZEPHIR_INIT_VAR(_3);
		zephir_fetch_safe_class(_4, formatter);
		_5 = zend_fetch_class(Z_STRVAL_P(_4), Z_STRLEN_P(_4), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_3, _5);
		if (zephir_has_constructor(_3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("formatter"), _3 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(owl_log_exception_invalidformatterexception_ce, "Formatter set error", "owl/Log/AbstractWriter.zep", 99);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Log_AbstractWriter, format) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *record, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "format", NULL, 0, record);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Filter records by levels
 */
PHP_METHOD(Owl_Log_AbstractWriter, filterRecords) {

	HashTable *_2;
	HashPosition _1;
	zval *records_param = NULL, *index = NULL, *record = NULL, *_0, **_3, *_4 = NULL, *_5;
	zval *records = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &records_param);

	zephir_get_arrval(records, records_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("levels"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		RETURN_CTOR(records);
	}
	zephir_is_iterable(records, &_2, &_1, 1, 0, "owl/Log/AbstractWriter.zep", 125);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(index, _2, _1);
		ZEPHIR_GET_HVALUE(record, _3);
		ZEPHIR_OBS_NVAR(_4);
		zephir_read_property(&_4, record, SL("level"), PH_NOISY_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("levels"), PH_NOISY_CC);
		if (!(zephir_fast_in_array(_4, _5 TSRMLS_CC))) {
			zephir_array_unset(&records, index, PH_SEPARATE);
		}
	}
	RETURN_CTOR(records);

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractWriter, commit) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *records_param = NULL, *_0, *_1, *_2 = NULL, *_3, *_4;
	zval *records = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &records_param);

	zephir_get_arrval(records, records_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("records"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "filterrecords", NULL, 0, records);
	zephir_check_call_status();
	zephir_fast_array_merge(_0, &(_1), &(_2) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("records"), _0 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("records"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("recordsInterval"), PH_NOISY_CC);
	if (ZEPHIR_LE_LONG(_4, zephir_fast_count_int(_3 TSRMLS_CC))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "push", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractWriter, push) {

	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *record = NULL, *_0, **_3, *_4 = NULL, *_7;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("records"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "owl/Log/AbstractWriter.zep", 152);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(record, _3);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "format", &_5, 0, record);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(record, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", &_6, 0, record);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_7);
	array_init(_7);
	zephir_update_property_this(this_ptr, SL("records"), _7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Write record
 */
PHP_METHOD(Owl_Log_AbstractWriter, write) {

	zval *record_param = NULL;
	zval *record = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record_param);

	zephir_get_strval(record, record_param);



}

PHP_METHOD(Owl_Log_AbstractWriter, __construct) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("options"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("records"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("levels"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

