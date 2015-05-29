
extern zend_class_entry *owl_http_responseinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Http_ResponseInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_responseinterface_setcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_http_responseinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Http_ResponseInterface, send, NULL)
	PHP_ABSTRACT_ME(Owl_Http_ResponseInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Owl_Http_ResponseInterface, setCode, arginfo_owl_http_responseinterface_setcode)
	PHP_ABSTRACT_ME(Owl_Http_ResponseInterface, getCode, NULL)
	PHP_FE_END
};
