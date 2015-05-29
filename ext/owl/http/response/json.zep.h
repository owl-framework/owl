
extern zend_class_entry *owl_http_response_json_ce;

ZEPHIR_INIT_CLASS(Owl_Http_Response_Json);

PHP_METHOD(Owl_Http_Response_Json, __construct);
PHP_METHOD(Owl_Http_Response_Json, setContent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_response_json_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_http_response_json_method_entry) {
	PHP_ME(Owl_Http_Response_Json, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Http_Response_Json, setContent, arginfo_owl_http_response_json_setcontent, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
