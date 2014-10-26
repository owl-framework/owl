
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Owl_Application) {

	ZEPHIR_REGISTER_CLASS(Owl, Application, owl, application, owl_application_method_entry, 0);

	zend_declare_property_null(owl_application_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_application_ce, SL("response"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Application, getRequest) {


	RETURN_MEMBER(this_ptr, "request");

}

PHP_METHOD(Owl_Application, getResponse) {


	RETURN_MEMBER(this_ptr, "response");

}

PHP_METHOD(Owl_Application, bootstrap) {



}

PHP_METHOD(Owl_Application, run) {



}

