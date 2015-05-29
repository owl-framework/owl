
extern zend_class_entry *owl_router_http_dynamicroute_ce;

ZEPHIR_INIT_CLASS(Owl_Router_Http_DynamicRoute);

PHP_METHOD(Owl_Router_Http_DynamicRoute, __construct);
PHP_METHOD(Owl_Router_Http_DynamicRoute, getPattern);
PHP_METHOD(Owl_Router_Http_DynamicRoute, match);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_router_http_dynamicroute___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_router_http_dynamicroute_match, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_router_http_dynamicroute_method_entry) {
	PHP_ME(Owl_Router_Http_DynamicRoute, __construct, arginfo_owl_router_http_dynamicroute___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Router_Http_DynamicRoute, getPattern, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Router_Http_DynamicRoute, match, arginfo_owl_router_http_dynamicroute_match, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
