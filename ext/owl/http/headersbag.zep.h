
extern zend_class_entry *owl_http_headersbag_ce;

ZEPHIR_INIT_CLASS(Owl_Http_HeadersBag);

PHP_METHOD(Owl_Http_HeadersBag, send);

ZEPHIR_INIT_FUNCS(owl_http_headersbag_method_entry) {
	PHP_ME(Owl_Http_HeadersBag, send, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
