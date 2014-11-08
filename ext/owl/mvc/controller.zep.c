
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
#include "kernel/exception.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_Mvc_Controller) {

	ZEPHIR_REGISTER_CLASS(Owl\\Mvc, Controller, owl, mvc_controller, owl_mvc_controller_method_entry, 0);

	zend_declare_property_null(owl_mvc_controller_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Mvc_Controller, getRequest) {


	RETURN_MEMBER(this_ptr, "request");

}

PHP_METHOD(Owl_Mvc_Controller, dispatch) {

	zend_bool _0;
	zval *request, *response = NULL;

	zephir_fetch_params(0, 1, 1, &request, &response);

	if (!response) {
		response = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(request, owl_http_request_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'Owl\\Http\\Request'", "", 0);
		return;
	}
	_0 = Z_TYPE_P(response) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(response, owl_http_response_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'Owl\\Http\\Response'", "", 0);
		return;
	}

}

