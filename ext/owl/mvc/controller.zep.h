
extern zend_class_entry *owl_mvc_controller_ce;

ZEPHIR_INIT_CLASS(Owl_Mvc_Controller);

PHP_METHOD(Owl_Mvc_Controller, getRequest);
PHP_METHOD(Owl_Mvc_Controller, dispatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_mvc_controller_dispatch, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Owl\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, response, Owl\\Http\\Response, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_mvc_controller_method_entry) {
	PHP_ME(Owl_Mvc_Controller, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Mvc_Controller, dispatch, arginfo_owl_mvc_controller_dispatch, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
