
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


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

	/**
	 * @var boolean
	 */
	zend_declare_property_bool(owl_http_response_ce, SL("sent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(owl_http_response_ce, SL("STATUS_CODE_OK"), 200 TSRMLS_CC);

	zend_class_implements(owl_http_response_ce TSRMLS_CC, 1, owl_http_responseinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Owl_Http_Response, getStatusCode) {


	RETURN_MEMBER(this_ptr, "statusCode");

}

/**
 */
PHP_METHOD(Owl_Http_Response, setStatusCode) {

	zval *statusCode_param = NULL, *_0;
	int statusCode;

	zephir_fetch_params(0, 1, 0, &statusCode_param);

	statusCode = zephir_get_intval(statusCode_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, statusCode);
	zephir_update_property_this(this_ptr, SL("statusCode"), _0 TSRMLS_CC);

}

/**
 */
PHP_METHOD(Owl_Http_Response, getContent) {


	RETURN_MEMBER(this_ptr, "content");

}

/**
 */
PHP_METHOD(Owl_Http_Response, setContent) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("content"), content TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 */
PHP_METHOD(Owl_Http_Response, __toString) {


	RETURN_MEMBER(this_ptr, "content");

}

/**
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
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 4, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("headers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if the response is already sent
 */
PHP_METHOD(Owl_Http_Response, isSent) {


	RETURN_MEMBER(this_ptr, "sent");

}

PHP_METHOD(Owl_Http_Response, send) {

	zval *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "http_response_code", NULL, 5, _0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "send", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("content"), PH_NOISY_CC);
	zephir_get_strval(_3, _2);
	zend_print_zval(_3, 0);
	zephir_update_property_this(this_ptr, SL("sent"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Owl_Http_Response, redirect) {

	int code, ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *code_param = NULL, *_0, *_1 = NULL;
	zval *location = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &location_param, &code_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}
	if (!code_param) {
		code = 302;
	} else {
		code = zephir_get_intval(code_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Location", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, _1, location);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, code);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_THIS();

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

