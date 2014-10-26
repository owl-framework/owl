
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


ZEPHIR_INIT_CLASS(Owl_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Owl\\Http, Request, owl, http_request, owl_http_request_method_entry, 0);

	zend_declare_property_null(owl_http_request_ce, SL("method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Http_Request, getMethod) {


	RETURN_MEMBER(this_ptr, "method");

}

PHP_METHOD(Owl_Http_Request, getParam) {



}

PHP_METHOD(Owl_Http_Request, getPost) {



}

PHP_METHOD(Owl_Http_Request, getServer) {



}

PHP_METHOD(Owl_Http_Request, getScheme) {



}

