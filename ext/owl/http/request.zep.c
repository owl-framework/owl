
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Owl\\Http, Request, owl, http_request, owl_http_request_method_entry, 0);

	zend_declare_property_string(owl_http_request_ce, SL("method"), "GET", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(owl_http_request_ce, SL("GET"), "GET" TSRMLS_CC);

	zend_declare_class_constant_string(owl_http_request_ce, SL("POST"), "POST" TSRMLS_CC);

	zend_declare_class_constant_string(owl_http_request_ce, SL("PUT"), "PUT" TSRMLS_CC);

	zend_declare_class_constant_string(owl_http_request_ce, SL("DELETE"), "DELETE" TSRMLS_CC);

	zend_declare_class_constant_string(owl_http_request_ce, SL("OPTIONS"), "OPTIONS" TSRMLS_CC);

	zend_declare_class_constant_string(owl_http_request_ce, SL("HEAD"), "HEAD" TSRMLS_CC);

	zend_declare_class_constant_string(owl_http_request_ce, SL("TRACE"), "TRACE" TSRMLS_CC);

	zend_declare_class_constant_string(owl_http_request_ce, SL("CONNECT"), "CONNECT" TSRMLS_CC);

	zend_declare_class_constant_string(owl_http_request_ce, SL("PATCH"), "PATCH" TSRMLS_CC);

	zend_declare_class_constant_string(owl_http_request_ce, SL("PROPFIND"), "PROPFIND" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Http_Request, getMethod) {


	RETURN_MEMBER(this_ptr, "method");

}

PHP_METHOD(Owl_Http_Request, getParam) {



}

PHP_METHOD(Owl_Http_Request, getPost) {

	zval *key_param = NULL, *_POST, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	if (zephir_array_isset(_POST, key)) {
		zephir_array_fetch(&_0, _POST, key, PH_NOISY | PH_READONLY, "owl/Http/Request.zep", 28 TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Owl_Http_Request, getServer) {

	zval *key_param = NULL, *_SERVER, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset(_SERVER, key)) {
		zephir_array_fetch(&_0, _SERVER, key, PH_NOISY | PH_READONLY, "owl/Http/Request.zep", 37 TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Owl_Http_Request, getScheme) {


	RETURN_STRING("http", 1);

}
