
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


ZEPHIR_INIT_CLASS(Owl_Event_Event) {

	ZEPHIR_REGISTER_CLASS(Owl\\Event, Event, owl, event_event, owl_event_event_method_entry, 0);

	zend_declare_property_null(owl_event_event_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_event_event_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Event_Event, getName) {


	RETURN_MEMBER(this_ptr, "name");

}

PHP_METHOD(Owl_Event_Event, getData) {


	RETURN_MEMBER(this_ptr, "data");

}

PHP_METHOD(Owl_Event_Event, __construct) {

	zval *name, *data;

	zephir_fetch_params(0, 2, 0, &name, &data);



	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);

}

