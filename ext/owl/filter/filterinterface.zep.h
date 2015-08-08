
extern zend_class_entry *owl_filter_filterinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Filter_FilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_filter_filterinterface_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_filter_filterinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Filter_FilterInterface, filter, arginfo_owl_filter_filterinterface_filter)
	PHP_FE_END
};
