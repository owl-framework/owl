
extern zend_class_entry *owl_filter_url_ce;

ZEPHIR_INIT_CLASS(Owl_Filter_Url);

PHP_METHOD(Owl_Filter_Url, filter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_filter_url_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_filter_url_method_entry) {
	PHP_ME(Owl_Filter_Url, filter, arginfo_owl_filter_url_filter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
