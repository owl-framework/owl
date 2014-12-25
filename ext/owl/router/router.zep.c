
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
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Owl_Router_Router) {

	ZEPHIR_REGISTER_CLASS(Owl\\Router, Router, owl, router_router, owl_router_router_method_entry, 0);

	zend_declare_property_string(owl_router_router_ce, SL("basePath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(owl_router_router_ce TSRMLS_CC, 1, owl_router_routerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Owl_Router_Router, getBasePath) {


	RETURN_MEMBER(this_ptr, "basePath");

}

PHP_METHOD(Owl_Router_Router, setBasePath) {

	zval *basePath;

	zephir_fetch_params(0, 1, 0, &basePath);



	zephir_update_property_this(this_ptr, SL("basePath"), basePath TSRMLS_CC);

}

PHP_METHOD(Owl_Router_Router, matchRequest) {

	zval *request;

	zephir_fetch_params(0, 1, 0, &request);



	if (!(zephir_is_instance_of(request, SL("Owl\\Router\\Owl\\Http\\Request") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'Owl\\Router\\Owl\\Http\\Request'", "", 0);
		return;
	}

}

PHP_METHOD(Owl_Router_Router, match) {

	zval *uri_param = NULL, *method_param = NULL;
	zval *uri = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri_param, &method_param);

	zephir_get_strval(uri, uri_param);
	if (!method_param) {
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "GET", 1);
	} else {
		zephir_get_strval(method, method_param);
	}



}

