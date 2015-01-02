
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

PHP_METHOD(Owl_Event_Manager, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("listeners"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

