
extern zend_class_entry *owl_http_request_ce;

ZEPHIR_INIT_CLASS(Owl_Http_Request);

PHP_METHOD(Owl_Http_Request, getMethod);
PHP_METHOD(Owl_Http_Request, getParam);
PHP_METHOD(Owl_Http_Request, getPost);
PHP_METHOD(Owl_Http_Request, getServer);
PHP_METHOD(Owl_Http_Request, getScheme);

ZEPHIR_INIT_FUNCS(owl_http_request_method_entry) {
	PHP_ME(Owl_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getParam, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getPost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getServer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getScheme, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
