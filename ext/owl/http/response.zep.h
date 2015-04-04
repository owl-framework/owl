
extern zend_class_entry *owl_http_response_ce;

ZEPHIR_INIT_CLASS(Owl_Http_Response);

PHP_METHOD(Owl_Http_Response, getCode);
PHP_METHOD(Owl_Http_Response, setCode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_response_setcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_http_response_method_entry) {
	PHP_ME(Owl_Http_Response, getCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Response, setCode, arginfo_owl_http_response_setcode, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
