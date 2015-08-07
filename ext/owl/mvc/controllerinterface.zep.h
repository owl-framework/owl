
extern zend_class_entry *owl_mvc_controllerinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Mvc_ControllerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_mvc_controllerinterface___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, request, Owl\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, response, Owl\\Http\\Response, 0)
	ZEND_ARG_OBJ_INFO(0, di, Owl\\Di\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_mvc_controllerinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Mvc_ControllerInterface, __construct, arginfo_owl_mvc_controllerinterface___construct)
	PHP_FE_END
};
