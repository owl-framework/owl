
extern zend_class_entry *owl_mvc_viewinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Mvc_ViewInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_mvc_viewinterface_render, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_mvc_viewinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Mvc_ViewInterface, getPath, NULL)
	PHP_ABSTRACT_ME(Owl_Mvc_ViewInterface, render, arginfo_owl_mvc_viewinterface_render)
	PHP_FE_END
};
