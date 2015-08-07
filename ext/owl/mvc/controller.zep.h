
extern zend_class_entry *owl_mvc_controller_ce;

ZEPHIR_INIT_CLASS(Owl_Mvc_Controller);

PHP_METHOD(Owl_Mvc_Controller, getRequest);
PHP_METHOD(Owl_Mvc_Controller, getResponse);
PHP_METHOD(Owl_Mvc_Controller, getDi);
PHP_METHOD(Owl_Mvc_Controller, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_mvc_controller___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, request, Owl\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, response, Owl\\Http\\Response, 0)
	ZEND_ARG_OBJ_INFO(0, di, Owl\\Di\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_mvc_controller_method_entry) {
	PHP_ME(Owl_Mvc_Controller, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Mvc_Controller, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Mvc_Controller, getDi, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Mvc_Controller, __construct, arginfo_owl_mvc_controller___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
