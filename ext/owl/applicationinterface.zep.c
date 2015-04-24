
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_ApplicationInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl, ApplicationInterface, owl, applicationinterface, owl_applicationinterface_method_entry);

	zend_declare_class_constant_string(owl_applicationinterface_ce, SL("ENV_PRODUCTION"), "production" TSRMLS_CC);

	zend_declare_class_constant_string(owl_applicationinterface_ce, SL("ENV_DEVELOPMENT"), "development" TSRMLS_CC);

	zend_declare_class_constant_string(owl_applicationinterface_ce, SL("EVENT_BEFORE_HANDLE"), "beforeHandle" TSRMLS_CC);

	zend_declare_class_constant_string(owl_applicationinterface_ce, SL("EVENT_AFTER_HANDLE"), "afterHandle" TSRMLS_CC);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Owl_ApplicationInterface, __construct);

/**
 * Handle Http Request
 */
ZEPHIR_DOC_METHOD(Owl_ApplicationInterface, handle);

