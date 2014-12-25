
extern zend_class_entry *owl_router_router_ce;

ZEPHIR_INIT_CLASS(Owl_Router_Router);

PHP_METHOD(Owl_Router_Router, getBasePath);
PHP_METHOD(Owl_Router_Router, setBasePath);
PHP_METHOD(Owl_Router_Router, matchRequest);
PHP_METHOD(Owl_Router_Router, match);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_router_router_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_router_router_matchrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Owl\\Router\\Owl\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_router_router_match, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_router_router_method_entry) {
	PHP_ME(Owl_Router_Router, getBasePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Router_Router, setBasePath, arginfo_owl_router_router_setbasepath, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Router_Router, matchRequest, arginfo_owl_router_router_matchrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Router_Router, match, arginfo_owl_router_router_match, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
