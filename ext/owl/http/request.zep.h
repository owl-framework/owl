
extern zend_class_entry *owl_http_request_ce;

ZEPHIR_INIT_CLASS(Owl_Http_Request);

PHP_METHOD(Owl_Http_Request, getMethod);
PHP_METHOD(Owl_Http_Request, getParam);
PHP_METHOD(Owl_Http_Request, getPost);
PHP_METHOD(Owl_Http_Request, getServer);
PHP_METHOD(Owl_Http_Request, getScheme);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_request_getpost, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_http_request_method_entry) {
	PHP_ME(Owl_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getParam, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getPost, arginfo_owl_http_request_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getServer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getScheme, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
