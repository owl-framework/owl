
extern zend_class_entry *owl_router_routerinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Router_RouterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_router_routerinterface_matchrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Owl\\Http\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_router_routerinterface_match, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_router_routerinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Router_RouterInterface, matchRequest, arginfo_owl_router_routerinterface_matchrequest)
	PHP_ABSTRACT_ME(Owl_Router_RouterInterface, match, arginfo_owl_router_routerinterface_match)
  PHP_FE_END
};
