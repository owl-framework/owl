
extern zend_class_entry *owl_http_requestinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Http_RequestInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_requestinterface_getpost, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_http_requestinterface_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_http_requestinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Http_RequestInterface, getUri, NULL)
	PHP_ABSTRACT_ME(Owl_Http_RequestInterface, getPost, arginfo_owl_http_requestinterface_getpost)
	PHP_ABSTRACT_ME(Owl_Http_RequestInterface, getServer, arginfo_owl_http_requestinterface_getserver)
	PHP_ABSTRACT_ME(Owl_Http_RequestInterface, getScheme, NULL)
  PHP_FE_END
};
