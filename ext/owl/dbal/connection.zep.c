
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Owl_DBAL_Connection) {

	ZEPHIR_REGISTER_CLASS(Owl\\DBAL, Connection, owl, dbal_connection, owl_dbal_connection_method_entry, 0);

	/**
	 * Current used driver
	 *
	 * @var Driver\DriverInterface
	 */
	zend_declare_property_null(owl_dbal_connection_ce, SL("driver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Current used db platform (MySQL|PgSQL)
	 *
	 * @var Platform\PlatformInterface
	 */
	zend_declare_property_null(owl_dbal_connection_ce, SL("platform"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Current used driver
 *
 * @var Driver\DriverInterface
 */
PHP_METHOD(Owl_DBAL_Connection, getDriver) {


	RETURN_MEMBER(this_ptr, "driver");

}

/**
 * Current used db platform (MySQL|PgSQL)
 *
 * @var Platform\PlatformInterface
 */
PHP_METHOD(Owl_DBAL_Connection, getPlatform) {


	RETURN_MEMBER(this_ptr, "platform");

}

/**
 * Construct connection
 */
PHP_METHOD(Owl_DBAL_Connection, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, *eventsManager = NULL, *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &eventsManager);

	if (!eventsManager) {
		ZEPHIR_CPY_WRT(eventsManager, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(eventsManager);
	}


	if (Z_TYPE_P(eventsManager) == IS_NULL) {
		ZEPHIR_INIT_NVAR(eventsManager);
		object_init_ex(eventsManager, owl_event_manager_ce);
		if (zephir_has_constructor(eventsManager TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "__construct", NULL, 0);
			zephir_check_call_status();
		}
	}
	if (zephir_array_isset_string(parameters, SS("driver"))) {
		zephir_array_fetch_string(&_0, parameters, SL("driver"), PH_NOISY | PH_READONLY, "owl/DBAL/Connection.zep", 40 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("driver"), _0 TSRMLS_CC);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, _1, "getnewplatform", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("platform"), _2 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Driver not found in $parameters", "owl/DBAL/Connection.zep", 47);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "seteventsmanager", NULL, 0, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Insert a row in the table with the specified data and types
 * returns the number of affected rows
 */
PHP_METHOD(Owl_DBAL_Connection, insert) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *data = NULL, *types = NULL;
	zval *table_param = NULL, *data_param = NULL, *types_param = NULL, *query, *stmt = NULL, *value = NULL, *set, *columnName = NULL, *fields, **_2, *_3, *_4 = NULL, *_5, *_6 = NULL, *_7, *_8, *_9;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &data_param, &types_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	data = data_param;

	if (!types_param) {
		ZEPHIR_INIT_VAR(types);
		array_init(types);
	} else {
	types = types_param;

	}
	ZEPHIR_INIT_VAR(set);
	array_init(set);


	ZEPHIR_INIT_VAR(fields);
	zephir_array_keys(fields, data TSRMLS_CC);
	zephir_is_iterable(data, &_1, &_0, 1, 0, "owl/DBAL/Connection.zep", 76);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(columnName, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (zephir_array_isset(types, columnName)) {
			zephir_array_fetch(&_3, types, columnName, PH_NOISY | PH_READONLY, "owl/DBAL/Connection.zep", 65 TSRMLS_CC);
			if (ZEPHIR_IS_LONG(_3, 10)) {
				zephir_array_append(&set, value, PH_SEPARATE, "owl/DBAL/Connection.zep", 66);
				zephir_array_unset(&data, columnName, PH_SEPARATE);
			} else {
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, ":", columnName, "");
				zephir_array_append(&set, _4, PH_SEPARATE, "owl/DBAL/Connection.zep", 69);
			}
		} else {
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVS(_4, ":", columnName, "");
			zephir_array_append(&set, _4, PH_SEPARATE, "owl/DBAL/Connection.zep", 72);
		}
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("platform"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_6, _5, "wrap", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	zephir_fast_join_str(_7, SL(","), fields TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	zephir_fast_join_str(_8, SL(","), set TSRMLS_CC);
	ZEPHIR_INIT_VAR(query);
	ZEPHIR_CONCAT_SVSVSVS(query, "INSERT INTO ", _6, " (", _7, ")  VALUES (", _8, ")");
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&stmt, _9, "prepare", NULL, 0, query);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(stmt, "execute", NULL, 0, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Update row(s) of table and returns the number of updated rows
 */
PHP_METHOD(Owl_DBAL_Connection, update) {

	zephir_fcall_cache_entry *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3;
	HashPosition _2;
	zval *data = NULL, *identifiers = NULL, *types = NULL;
	zval *table_param = NULL, *data_param = NULL, *identifiers_param = NULL, *types_param = NULL, *set, *stmt = NULL, *columnName = NULL, *_0 = NULL, *_1, **_4, *_5, *_6 = NULL, *_7 = NULL, *_8, *cnt, *_9, *_10 = NULL, *_11 = NULL, *_12, *_13;
	zval *table = NULL, *query = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &data_param, &identifiers_param, &types_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	data = data_param;

	identifiers = identifiers_param;

	if (!types_param) {
		ZEPHIR_INIT_VAR(types);
		array_init(types);
	} else {
	types = types_param;

	}
	ZEPHIR_INIT_VAR(set);
	array_init(set);


	ZEPHIR_INIT_VAR(_1);
	zephir_array_keys(_1, data TSRMLS_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "owl/DBAL/Connection.zep", 94);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(columnName, _4);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("platform"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_6, _5, "wrap", NULL, 0, columnName);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_VS(_7, _6, " = ?");
		zephir_array_append(&set, _7, PH_SEPARATE, "owl/DBAL/Connection.zep", 91);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("platform"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_6, _5, "wrap", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	zephir_fast_join_str(_8, SL(", "), set TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_7);
	ZEPHIR_CONCAT_SVSV(_7, "UPDATE ", _6, " SET ", _8);
	zephir_get_strval(query, _7);
	ZEPHIR_INIT_VAR(cnt);
	ZVAL_LONG(cnt, zephir_fast_count_int(identifiers TSRMLS_CC));
	if (ZEPHIR_GT_LONG(cnt, 0)) {
		zephir_concat_self_str(&query, " WHERE ", sizeof(" WHERE ")-1 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(cnt, 1)) {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("platform"), PH_NOISY_CC);
			Z_SET_ISREF_P(identifiers);
			ZEPHIR_CALL_FUNCTION(&_11, "key", NULL, 5, identifiers);
			Z_UNSET_ISREF_P(identifiers);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_10, _9, "wrap", NULL, 0, _11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_12);
			ZEPHIR_CONCAT_VS(_12, _10, " = ?");
			zephir_concat_self(&query, _12 TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "It's not implemented", "owl/DBAL/Connection.zep", 105);
			return;
		}
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&stmt, _5, "prepare", NULL, 0, query);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CALL_FUNCTION(&_6, "array_values", &_14, 6, data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_10, "array_values", &_14, 6, identifiers);
	zephir_check_call_status();
	zephir_fast_array_merge(_13, &(_6), &(_10) TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(stmt, "execute", NULL, 0, _13);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Delete rows where $column = $key in $table
 * return the number of affected rows
 */
PHP_METHOD(Owl_DBAL_Connection, deleteByColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *column_param = NULL, *value, *type_param = NULL, *_0, *_1, *_2 = NULL, *_3;
	zval *table = NULL, *column = NULL, *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &column_param, &value, &type_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (unlikely(Z_TYPE_P(column_param) != IS_STRING && Z_TYPE_P(column_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'column' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(column_param) == IS_STRING)) {
		zephir_get_strval(column, column_param);
	} else {
		ZEPHIR_INIT_VAR(column);
		ZVAL_EMPTY_STRING(column);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("platform"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "wrap", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSVSV(_3, "DELETE FROM ", _2, " WHERE ", column, " = ", value);
	ZEPHIR_RETURN_CALL_METHOD(_0, "execute", NULL, 0, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Delete rows from tables where identifiers are specified
 * return the number of affected rows
 */
PHP_METHOD(Owl_DBAL_Connection, delete) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool first = 1;
	zval *identifiers = NULL, *types = NULL;
	zval *table_param = NULL, *identifiers_param = NULL, *types_param = NULL, *query = NULL, *key = NULL, *value = NULL, *_0, *_1 = NULL, **_4, *_5;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &identifiers_param, &types_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	identifiers = identifiers_param;

	if (!types_param) {
		ZEPHIR_INIT_VAR(types);
		array_init(types);
	} else {
	types = types_param;

	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("platform"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "wrap", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(query);
	ZEPHIR_CONCAT_SVS(query, "DELETE FROM ", _1, " WHERE ");
	zephir_is_iterable(identifiers, &_3, &_2, 0, 0, "owl/DBAL/Connection.zep", 150);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		if (!first) {
			zephir_concat_self_str(&query, SL(" AND") TSRMLS_CC);
		} else {
			first = 0;
		}
		ZEPHIR_INIT_NVAR(query);
		ZEPHIR_CONCAT_SVSV(query, " ", key, " = ", value);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_5, "execute", NULL, 0, query);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepares a statement for execution and returns a statement
 */
PHP_METHOD(Owl_DBAL_Connection, prepare) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement, *smt = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&smt, _0, "prepare", NULL, 0, statement);
	zephir_check_call_status();
	RETURN_CCTOR(smt);

}

