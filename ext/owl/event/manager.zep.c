
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

ZEPHIR_INIT_CLASS(Owl_Event_Manager) {

	ZEPHIR_REGISTER_CLASS(Owl\\Event, Manager, owl, event_manager, owl_event_manager_method_entry, 0);

	zend_declare_property_null(owl_event_manager_ce, SL("listeners"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Event_Manager, listen) {

	zval *eventName, *callback;

	zephir_fetch_params(0, 2, 0, &eventName, &callback);

	if (unlikely(zephir_is_callable(callback TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'callback' must be callable") TSRMLS_CC);
		RETURN_NULL();
	}



	zephir_update_property_array_multi(this_ptr, SL("listeners"), &callback TSRMLS_CC, SL("za"), 1, eventName);

}

PHP_METHOD(Owl_Event_Manager, emit) {

	zephir_fcall_cache_entry *_7 = NULL;
	zval *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *eventName_param = NULL, *data = NULL, *events, *callback = NULL, *_0, **_3, *_4 = NULL, *_6 = NULL;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &eventName_param, &data);

	zephir_get_strval(eventName, eventName_param);
	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(events);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("listeners"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&events, _0, eventName, 0 TSRMLS_CC)) {
		zephir_is_iterable(events, &_2, &_1, 0, 0, "owl/Event/Manager.zep", 25);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(callback, _3);
			if (Z_TYPE_P(callback) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_4);
				ZEPHIR_INIT_NVAR(_5);
				zephir_create_array(_5, 1, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_6);
				object_init_ex(_6, owl_event_event_ce);
				ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_7, 0, eventName, data);
				zephir_check_call_status();
				zephir_array_fast_append(_5, _6);
				ZEPHIR_CALL_USER_FUNC_ARRAY(_4, callback, _5);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_4);
				object_init_ex(_4, owl_event_event_ce);
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_7, 0, eventName, data);
				zephir_check_call_status();
				ZEPHIR_CALL_ZVAL_FUNCTION(NULL, callback, NULL, 0, _4);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Event_Manager, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("listeners"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

