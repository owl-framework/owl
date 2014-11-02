
extern zend_class_entry *owl_http_response_ce;

ZEPHIR_INIT_CLASS(Owl_Http_Response);

PHP_METHOD(Owl_Http_Response, getCode);

ZEPHIR_INIT_FUNCS(owl_http_response_method_entry) {
	PHP_ME(Owl_Http_Response, getCode, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
