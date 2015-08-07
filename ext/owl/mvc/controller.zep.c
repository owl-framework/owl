
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

	/**
	 * @var \Owl\Http\ResponseInterface
	 */
	zend_declare_property_null(owl_mvc_controller_ce, SL("response"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Di\ContainerInterface
	 */
	zend_declare_property_null(owl_mvc_controller_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(owl_mvc_controller_ce TSRMLS_CC, 1, owl_mvc_controllerinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Owl_Mvc_Controller, getRequest) {


	RETURN_MEMBER(this_ptr, "request");

}

/**
 */
PHP_METHOD(Owl_Mvc_Controller, getResponse) {


	RETURN_MEMBER(this_ptr, "response");

}

/**
 */
PHP_METHOD(Owl_Mvc_Controller, getDi) {


	RETURN_MEMBER(this_ptr, "di");

}

PHP_METHOD(Owl_Mvc_Controller, __construct) {

	zval *request, *response, *di;

	zephir_fetch_params(0, 3, 0, &request, &response, &di);



	zephir_update_property_this(this_ptr, SL("request"), request TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("response"), response TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);

}

