
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


ZEPHIR_INIT_CLASS(Owl_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Owl\\Http, Response, owl, http_response, owl_http_response_method_entry, 0);

	zend_declare_property_long(owl_http_response_ce, SL("code"), 200, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(owl_http_response_ce, SL("STATUS_CODE_OK"), 200 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Http_Response, getCode) {


	RETURN_MEMBER(this_ptr, "code");

}

PHP_METHOD(Owl_Http_Response, setCode) {

	zval *code;

	zephir_fetch_params(0, 1, 0, &code);



	zephir_update_property_this(this_ptr, SL("code"), code TSRMLS_CC);

}

