
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Owl_Cache_Driver_NativeArray) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Cache\\Driver, NativeArray, owl, cache_driver_nativearray, owl_cache_driver_cachedriver_ce, owl_cache_driver_nativearray_method_entry, 0);

	zend_declare_property_null(owl_cache_driver_nativearray_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array|null
	 */
	zend_declare_property_null(owl_cache_driver_nativearray_ce, SL("instance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Cache_Driver_NativeArray, __construct) {

	zval *options_param = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Cache_Driver_NativeArray, setInstance) {

	zval *instance_param = NULL;
	zval *instance = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &instance_param);

	zephir_get_arrval(instance, instance_param);


	zephir_update_property_this(this_ptr, SL("instance"), instance TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return array
 */
PHP_METHOD(Owl_Cache_Driver_NativeArray, getInstance) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("instance"), _1 TSRMLS_CC);
		RETURN_MM_MEMBER(this_ptr, "instance");
	}
	RETURN_MM_MEMBER(this_ptr, "instance");

}

PHP_METHOD(Owl_Cache_Driver_NativeArray, __destruct) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		zephir_unset_property(this_ptr, "instance" TSRMLS_CC);
	}

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Cache_Driver_NativeArray, save) {

	zval *id, *data, *lifetime = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &id, &data, &lifetime);

	if (!lifetime) {
		ZEPHIR_INIT_VAR(lifetime);
		ZVAL_LONG(lifetime, 3600);
	}


	zephir_update_property_array(this_ptr, SL("instance"), id, data TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Cache_Driver_NativeArray, delete) {

	zval *id, *_0;

	zephir_fetch_params(0, 1, 0, &id);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	zephir_array_unset(&_0, id, PH_SEPARATE);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Cache_Driver_NativeArray, get) {

	zval *id_param = NULL, *value, *_0;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (unlikely(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(id, id_param);
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, id, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_BOOL(0);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Cache_Driver_NativeArray, flush) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("instance"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

