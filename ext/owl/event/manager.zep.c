
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
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"

ZEPHIR_INIT_CLASS(Owl_Event_Manager) {

	ZEPHIR_REGISTER_CLASS(Owl\\Event, Manager, owl, event_manager, owl_event_manager_method_entry, 0);

	zend_declare_property_null(owl_event_manager_ce, SL("listeners"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Event_Manager, listen) {

	zval *eventName, *callback;

	zephir_fetch_params(0, 2, 0, &eventName, &callback);



	zephir_update_property_array_multi(this_ptr, SL("listeners"), &callback TSRMLS_CC, SL("za"), 1, eventName);

}

PHP_METHOD(Owl_Event_Manager, emit) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *eventName_param = NULL, *data = NULL, *events, *callback = NULL, *_0, **_3;
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
		zephir_is_iterable(events, &_2, &_1, 0, 0, "owl/Event/Manager.zep", 21);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(callback, _3);
			ZEPHIR_CALL_ZVAL_FUNCTION(NULL, callback, NULL, data);
			zephir_check_call_status();
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

