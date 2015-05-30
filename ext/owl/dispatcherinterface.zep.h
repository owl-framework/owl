
extern zend_class_entry *owl_dispatcherinterface_ce;

ZEPHIR_INIT_CLASS(Owl_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_dispatcherinterface_dispatch, 0, 0, 2)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, callParameters)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_dispatcherinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_DispatcherInterface, dispatch, arginfo_owl_dispatcherinterface_dispatch)
	PHP_FE_END
};
