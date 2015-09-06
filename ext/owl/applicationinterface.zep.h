
extern zend_class_entry *owl_applicationinterface_ce;

ZEPHIR_INIT_CLASS(Owl_ApplicationInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_applicationinterface___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, di, Owl\\Di\\ContainerInterface, 1)
	ZEND_ARG_OBJ_INFO(0, eventManager, Owl\\Event\\Manager, 1)
	ZEND_ARG_INFO(0, env)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_applicationinterface_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Owl\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Owl\\Http\\ResponseInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_applicationinterface_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_applicationinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_ApplicationInterface, __construct, arginfo_owl_applicationinterface___construct)
	PHP_ABSTRACT_ME(Owl_ApplicationInterface, handle, arginfo_owl_applicationinterface_handle)
	PHP_ABSTRACT_ME(Owl_ApplicationInterface, setDefaultNamespace, arginfo_owl_applicationinterface_setdefaultnamespace)
	PHP_FE_END
};
