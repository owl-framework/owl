
extern zend_class_entry *owl_router_http_staticroute_ce;

ZEPHIR_INIT_CLASS(Owl_Router_Http_StaticRoute);

PHP_METHOD(Owl_Router_Http_StaticRoute, match);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_router_http_staticroute_match, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_router_http_staticroute_method_entry) {
	PHP_ME(Owl_Router_Http_StaticRoute, match, arginfo_owl_router_http_staticroute_match, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
