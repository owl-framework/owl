
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
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Owl_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Owl\\Http, Response, owl, http_response, owl_http_response_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_long(owl_http_response_ce, SL("code"), 200, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(owl_http_response_ce, SL("content"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Std\ArrayBag
	 */
	zend_declare_property_null(owl_http_response_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(owl_http_response_ce, SL("STATUS_CODE_OK"), 200 TSRMLS_CC);

	zend_class_implements(owl_http_response_ce TSRMLS_CC, 1, owl_http_responseinterface_ce);
	return SUCCESS;

}

/**
 * @var int
 */
PHP_METHOD(Owl_Http_Response, getCode) {


	RETURN_MEMBER(this_ptr, "code");

}

/**
 * @var int
 */
PHP_METHOD(Owl_Http_Response, setCode) {

	zval *code;

	zephir_fetch_params(0, 1, 0, &code);



	zephir_update_property_this(this_ptr, SL("code"), code TSRMLS_CC);

}

/**
 * @var string
 */
PHP_METHOD(Owl_Http_Response, getContent) {


	RETURN_MEMBER(this_ptr, "content");

}

/**
 * @var string
 */
PHP_METHOD(Owl_Http_Response, setContent) {

	zval *content;

	zephir_fetch_params(0, 1, 0, &content);



	zephir_update_property_this(this_ptr, SL("content"), content TSRMLS_CC);

}

/**
 * @var \Owl\Std\ArrayBag
 */
PHP_METHOD(Owl_Http_Response, getHeaders) {


	RETURN_MEMBER(this_ptr, "headers");

}

PHP_METHOD(Owl_Http_Response, __construct) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, owl_std_arraybag_ce);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_2, 12, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("headers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Http_Response, send) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("code"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "http_response_code", &_1, 14, _0);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
	zend_print_zval(_2, 0);
	RETURN_MM_BOOL(1);

}

