
extern zend_class_entry *owl_http_request_ce;

ZEPHIR_INIT_CLASS(Owl_Http_Request);

PHP_METHOD(Owl_Http_Request, getMethod);
PHP_METHOD(Owl_Http_Request, getUri);
PHP_METHOD(Owl_Http_Request, getParam);
PHP_METHOD(Owl_Http_Request, getPost);
PHP_METHOD(Owl_Http_Request, getServer);
PHP_METHOD(Owl_Http_Request, getScheme);
PHP_METHOD(Owl_Http_Request, __construct);
PHP_METHOD(Owl_Http_Request, createFromGlobals);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_request_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_request_getpost, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_request_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_request___construct, 0, 0, 6)
	ZEND_ARG_INFO(0, get)
	ZEND_ARG_INFO(0, post)
	ZEND_ARG_INFO(0, server)
	ZEND_ARG_INFO(0, headers)
	ZEND_ARG_INFO(0, files)
	ZEND_ARG_INFO(0, cookies)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_http_request_method_entry) {
	PHP_ME(Owl_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getParam, arginfo_owl_http_request_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getPost, arginfo_owl_http_request_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getServer, arginfo_owl_http_request_getserver, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, getScheme, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Http_Request, __construct, arginfo_owl_http_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Http_Request, createFromGlobals, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
