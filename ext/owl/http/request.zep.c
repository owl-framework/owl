
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Owl_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Owl\\Http, Request, owl, http_request, owl_http_request_method_entry, 0);

	zend_declare_property_string(owl_http_request_ce, SL("method"), "GET", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Std\ArrayBag
	 */
	zend_declare_property_null(owl_http_request_ce, SL("get"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Std\ArrayBag
	 */
	zend_declare_property_null(owl_http_request_ce, SL("post"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Std\ArrayBag
	 */
	zend_declare_property_null(owl_http_request_ce, SL("server"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Std\ArrayBag
	 */
	zend_declare_property_null(owl_http_request_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Std\ArrayBag
	 */
	zend_declare_property_null(owl_http_request_ce, SL("files"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Std\ArrayBag
	 */
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

/**
 * Get request URI
 */
PHP_METHOD(Owl_Http_Request, getUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "REQUEST_URI", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get request path (URI without GET parameters)
 */
PHP_METHOD(Owl_Http_Request, getPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, _1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 5);
	ZEPHIR_RETURN_CALL_FUNCTION("parse_url", NULL, 20, _0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Owl_Http_Request, getParam) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

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
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("get"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, key, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Owl_Http_Request, getPost) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

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
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("post"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, key, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Owl_Http_Request, getServer) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

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
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, key, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Owl_Http_Request, getScheme) {


	RETURN_STRING("http", 1);

}

PHP_METHOD(Owl_Http_Request, __construct) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *get, *post, *server, *headers, *files, *cookies, *_0, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 0, &get, &post, &server, &headers, &files, &cookies);



	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, owl_std_arraybag_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_1, 4, get);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("get"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, owl_std_arraybag_ce);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_1, 4, post);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("post"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, owl_std_arraybag_ce);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_1, 4, server);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("server"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, owl_std_arraybag_ce);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_1, 4, headers);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("headers"), _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, owl_std_arraybag_ce);
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_1, 4, files);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("files"), _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	object_init_ex(_6, owl_std_arraybag_ce);
	ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_1, 4, cookies);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("cookies"), _6 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Http_Request, createFromGlobals) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_GET, *_POST, *_SERVER, *_FILES, *_COOKIE;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);

	object_init_ex(return_value, owl_http_request_ce);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 21, _GET, _POST, _SERVER, _0, _FILES, _COOKIE);
	zephir_check_call_status();
	RETURN_MM();

}

