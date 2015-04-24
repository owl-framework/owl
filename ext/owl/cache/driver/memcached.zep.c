
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
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */
ZEPHIR_INIT_CLASS(Owl_Cache_Driver_Memcached) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Cache\\Driver, Memcached, owl, cache_driver_memcached, owl_cache_driver_cachedriver_ce, owl_cache_driver_memcached_method_entry, 0);

	zend_declare_property_null(owl_cache_driver_memcached_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Memcached
	 */
	zend_declare_property_null(owl_cache_driver_memcached_ce, SL("instance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Cache_Driver_Memcached, __construct) {

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

PHP_METHOD(Owl_Cache_Driver_Memcached, setInstance) {

	zval *instance;

	zephir_fetch_params(0, 1, 0, &instance);



	zephir_update_property_this(this_ptr, SL("instance"), instance TSRMLS_CC);

}

PHP_METHOD(Owl_Cache_Driver_Memcached, getInstance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zephir_get_internal_ce(SS("memcached") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("instance"), _1 TSRMLS_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "localhost", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 11211);
		ZEPHIR_CALL_METHOD(NULL, _2, "addserver", NULL, _3, _4);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_MEMBER(this_ptr, "instance");
	}
	RETURN_MM_MEMBER(this_ptr, "instance");

}

PHP_METHOD(Owl_Cache_Driver_Memcached, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1, "resetserverlist", NULL);
		zephir_check_call_status();
		zephir_unset_property(this_ptr, "instance" TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Cache_Driver_Memcached, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id, *data, *lifeTime = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &id, &data, &lifeTime);

	if (!lifeTime) {
		ZEPHIR_INIT_VAR(lifeTime);
		ZVAL_LONG(lifeTime, 3600);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinstance", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "set", NULL, id, data, lifeTime);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Cache_Driver_Memcached, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinstance", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "delete", NULL, id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Cache_Driver_Memcached, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinstance", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Owl_Cache_Driver_Memcached, flush) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinstance", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "flush", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

