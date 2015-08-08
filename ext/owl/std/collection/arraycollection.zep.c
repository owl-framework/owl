
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Owl_Std_Collection_ArrayCollection) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Std\\Collection, ArrayCollection, owl, std_collection_arraycollection, owl_std_collection_abstractcollection_ce, owl_std_collection_arraycollection_method_entry, 0);

	zend_declare_property_null(owl_std_collection_arraycollection_ce, SL("elements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Std_Collection_ArrayCollection, __construct) {

	zval *elements_param = NULL;
	zval *elements = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(elements);
		array_init(elements);
	} else {
	elements = elements_param;

	}


	zephir_update_property_this(this_ptr, SL("elements"), elements TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Std_Collection_ArrayCollection, add) {

	zval *element;

	zephir_fetch_params(0, 1, 0, &element);



	zephir_update_property_array_append(this_ptr, SL("elements"), element TSRMLS_CC);

}

/**
 * Checks is collection empty?
 */
PHP_METHOD(Owl_Std_Collection_ArrayCollection, isEmpty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_LONG(_0, 0));

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Std_Collection_ArrayCollection, map) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *func, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &func);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_map", NULL, 34, func, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("elements"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Std_Collection_ArrayCollection, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *func, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &func);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_filter", NULL, 35, _0, func);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("elements"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Std_Collection_ArrayCollection, first) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("reset", NULL, 36, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Std_Collection_ArrayCollection, last) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("end", NULL, 37, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Std_Collection_ArrayCollection, getIterator) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 38, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Std_Collection_ArrayCollection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

