
extern zend_class_entry *owl_http_responseinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Http_ResponseInterface);

ZEPHIR_INIT_FUNCS(owl_http_responseinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Http_ResponseInterface, send, NULL)
  PHP_FE_END
};
