
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_DispatcherInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl, DispatcherInterface, owl, dispatcherinterface, owl_dispatcherinterface_method_entry);

	zend_declare_class_constant_string(owl_dispatcherinterface_ce, SL("EVENT_ROUTER_BEFORE_EXECUTE"), "dispatch:beforeExecuteRoute" TSRMLS_CC);

	zend_declare_class_constant_string(owl_dispatcherinterface_ce, SL("EVENT_ROUTER_AFTER_EXECUTE"), "dispatch:afterExecuteRoute" TSRMLS_CC);

	zend_declare_class_constant_string(owl_dispatcherinterface_ce, SL("EVENT_AFTER_ACTION"), "dispatch:afterAction" TSRMLS_CC);

	zend_declare_class_constant_string(owl_dispatcherinterface_ce, SL("EVENT_AFTER_INIT"), "dispatch:afterInitialize" TSRMLS_CC);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Owl_DispatcherInterface, dispatch);

