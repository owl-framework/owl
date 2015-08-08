
extern zend_class_entry *owl_http_response_ce;

ZEPHIR_INIT_CLASS(Owl_Http_Response);

PHP_METHOD(Owl_Http_Response, getStatusCode);
PHP_METHOD(Owl_Http_Response, setStatusCode);
PHP_METHOD(Owl_Http_Response, getContent);
PHP_METHOD(Owl_Http_Response, setContent);
PHP_METHOD(Owl_Http_Response, __toString);
PHP_METHOD(Owl_Http_Response, getHeaders);
PHP_METHOD(Owl_Http_Response, __construct);
PHP_METHOD(Owl_Http_Response, isSent);
PHP_METHOD(Owl_Http_Response, send);
PHP_METHOD(Owl_Http_Response, isOk);
PHP_METHOD(Owl_Http_Response, isServerError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_response_setstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, statusCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_response_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_http_response_method_entry) {
	PHP_ME(Owl_Http_Response, getStatusCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Response, setStatusCode, arginfo_owl_http_response_setstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Response, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Response, setContent, arginfo_owl_http_response_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Response, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Response, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Response, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Http_Response, isSent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Response, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Response, isOk, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Response, isServerError, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
