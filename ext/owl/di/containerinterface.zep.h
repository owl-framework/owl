
extern zend_class_entry *owl_di_containerinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Di_ContainerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_containerinterface_setservice, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_containerinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_containerinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_containerinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_containerinterface_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_di_containerinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Di_ContainerInterface, setService, arginfo_owl_di_containerinterface_setservice)
	PHP_ABSTRACT_ME(Owl_Di_ContainerInterface, set, arginfo_owl_di_containerinterface_set)
	PHP_ABSTRACT_ME(Owl_Di_ContainerInterface, has, arginfo_owl_di_containerinterface_has)
	PHP_ABSTRACT_ME(Owl_Di_ContainerInterface, get, arginfo_owl_di_containerinterface_get)
	PHP_ABSTRACT_ME(Owl_Di_ContainerInterface, getService, arginfo_owl_di_containerinterface_getservice)
	PHP_FE_END
};
