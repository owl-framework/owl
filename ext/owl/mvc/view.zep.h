
extern zend_class_entry *owl_mvc_view_ce;

ZEPHIR_INIT_CLASS(Owl_Mvc_View);

PHP_METHOD(Owl_Mvc_View, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_mvc_view_render, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_mvc_view_method_entry) {
	PHP_ME(Owl_Mvc_View, render, arginfo_owl_mvc_view_render, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
