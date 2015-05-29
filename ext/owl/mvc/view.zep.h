
extern zend_class_entry *owl_mvc_view_ce;

ZEPHIR_INIT_CLASS(Owl_Mvc_View);

PHP_METHOD(Owl_Mvc_View, getPath);
PHP_METHOD(Owl_Mvc_View, setPath);
PHP_METHOD(Owl_Mvc_View, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_mvc_view_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_mvc_view_render, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_mvc_view_method_entry) {
	PHP_ME(Owl_Mvc_View, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Mvc_View, setPath, arginfo_owl_mvc_view_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Mvc_View, render, arginfo_owl_mvc_view_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
