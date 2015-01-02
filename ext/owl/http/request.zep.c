
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

	zend_declare_property_null(owl_http_request_ce, SL("get"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_http_request_ce, SL("post"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_http_request_ce, SL("server"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_http_request_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_http_request_ce, SL("files"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_http_request_ce, SL("cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zend_class_implements(owl_http_request_ce TSRMLS_CC, 1, owl_http_requestinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Owl_Http_Request, getMethod) {


	RETURN_MEMBER(this_ptr, "method");

}

PHP_METHOD(Owl_Http_Request, getParam) {



}

PHP_METHOD(Owl_Http_Request, getPost) {

	zval *key_param = NULL, *_0, *_1, *_2;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("post"), PH_NOISY_CC);
	if (zephir_array_isset(_0, key)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("post"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, key, PH_NOISY | PH_READONLY, "owl/Http/Request.zep", 40 TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Owl_Http_Request, getServer) {

	zval *key_param = NULL, *_0, *_1, *_2;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	if (zephir_array_isset(_0, key)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, key, PH_NOISY | PH_READONLY, "owl/Http/Request.zep", 49 TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Owl_Http_Request, getScheme) {


	RETURN_STRING("http", 1);

}

