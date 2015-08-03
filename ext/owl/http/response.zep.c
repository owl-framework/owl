
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
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Owl_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Owl\\Http, Response, owl, http_response, owl_http_response_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_long(owl_http_response_ce, SL("statusCode"), 200, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(owl_http_response_ce, SL("content"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Owl\Http\HeadersBag
	 */
	zend_declare_property_null(owl_http_response_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(owl_http_response_ce, SL("STATUS_CODE_OK"), 200 TSRMLS_CC);

	zend_class_implements(owl_http_response_ce TSRMLS_CC, 1, owl_http_responseinterface_ce);
	return SUCCESS;

}

/**
 * @var int
 */
PHP_METHOD(Owl_Http_Response, getStatusCode) {


	RETURN_MEMBER(this_ptr, "statusCode");

}

/**
 * @var int
 */
PHP_METHOD(Owl_Http_Response, setStatusCode) {

	zval *statusCode;

	zephir_fetch_params(0, 1, 0, &statusCode);



	zephir_update_property_this(this_ptr, SL("statusCode"), statusCode TSRMLS_CC);

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
 * @var string
 */
PHP_METHOD(Owl_Http_Response, __toString) {


	RETURN_MEMBER(this_ptr, "content");

}

/**
 * @var \Owl\Http\HeadersBag
 */
PHP_METHOD(Owl_Http_Response, getHeaders) {


	RETURN_MEMBER(this_ptr, "headers");

}

PHP_METHOD(Owl_Http_Response, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, owl_http_headersbag_ce);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 3, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("headers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Http_Response, send) {

	zval *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "http_response_code", NULL, 4, _0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("content"), PH_NOISY_CC);
	zephir_get_strval(_2, _1);
	zend_print_zval(_2, 0);
	RETURN_MM_BOOL(1);

}

/**
 * Check whether status is OK
 */
PHP_METHOD(Owl_Http_Response, isOk) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_LONG(_0, 200));

}

/**
 * Check whether status is Server Error
 */
PHP_METHOD(Owl_Http_Response, isServerError) {

	zend_bool _1;
	zval *_0, *_2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 500);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
		_1 = ZEPHIR_LT_LONG(_2, 600);
	}
	RETURN_BOOL(_1);

}

