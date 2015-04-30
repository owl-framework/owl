
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
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

PHP_METHOD(Owl_Log_AbstractWriter, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("records"), PH_NOISY_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "push", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractWriter, getOption) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, *_0, *_1, *_4, *_5;
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
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_3, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "owl/Log/AbstractWriter.zep", 57 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	zephir_array_fetch(&_5, _4, option, PH_NOISY | PH_READONLY, "owl/Log/AbstractWriter.zep", 59 TSRMLS_CC);
	RETURN_CTOR(_5);

}

PHP_METHOD(Owl_Log_AbstractWriter, defaultFormatter) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, owl_log_formatter_line_ce);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
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
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "defaultformatter", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("formatter"), _1 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "formatter");

}

PHP_METHOD(Owl_Log_AbstractWriter, setFormatter) {

	zend_class_entry *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zend_bool _0;
	zval *formatter, _1, *_2 = NULL, *_4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &formatter);



	_0 = Z_TYPE_P(formatter) == IS_OBJECT;
	if (_0) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "Owl\\Log\\FormatterInterface", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "is_subclass_of", &_3, formatter, &_1);
		zephir_check_call_status();
		_0 = zephir_is_true(_2);
	}
	if (_0) {
		zephir_update_property_this(this_ptr, SL("formatter"), formatter TSRMLS_CC);
	}
	if (Z_TYPE_P(formatter) == IS_STRING) {
		if (!(zephir_class_exists(formatter, 1 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(owl_log_exception_invalidformatterexception_ce, "Formatter class is not exits", "owl/Log/AbstractWriter.zep", 86);
			return;
		}
		ZEPHIR_INIT_VAR(_4);
		zephir_fetch_safe_class(_5, formatter);
		_6 = zend_fetch_class(Z_STRVAL_P(_5), Z_STRLEN_P(_5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_4, _6);
		if (zephir_has_constructor(_4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("formatter"), _4 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Log_AbstractWriter, format) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *record, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getformatter", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "format", NULL, record);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Owl_Log_AbstractWriter, filterRecords) {

	zval *records_param = NULL;
	zval *records = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &records_param);

	zephir_get_arrval(records, records_param);


	RETURN_CTOR(records);

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_AbstractWriter, commit) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *records_param = NULL, *_0 = NULL, *_1, *_2;
	zval *records = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &records_param);

	zephir_get_arrval(records, records_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterrecords", NULL, records);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("records"), _0 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("records"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("recordsInterval"), PH_NOISY_CC);
	if (ZEPHIR_LT_LONG(_2, zephir_fast_count_int(_1 TSRMLS_CC))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "push", NULL);
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
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "owl/Log/AbstractWriter.zep", 127);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(record, _3);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "format", &_5, record);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(record, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", &_6, record);
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

