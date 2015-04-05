
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


ZEPHIR_INIT_CLASS(Owl_Mvc_Controller) {

	ZEPHIR_REGISTER_CLASS(Owl\\Mvc, Controller, owl, mvc_controller, owl_mvc_controller_method_entry, 0);

	/**
	 * @var \Owl\Http\RequestInterface
	 */
	zend_declare_property_null(owl_mvc_controller_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @var \Owl\Http\RequestInterface
 */
PHP_METHOD(Owl_Mvc_Controller, getRequest) {


	RETURN_MEMBER(this_ptr, "request");

}

PHP_METHOD(Owl_Mvc_Controller, __construct) {

	zval *request, *response = NULL;

	zephir_fetch_params(0, 1, 1, &request, &response);

	if (!response) {
		response = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("request"), request TSRMLS_CC);

}

