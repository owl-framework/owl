
extern zend_class_entry *owl_application_ce;

ZEPHIR_INIT_CLASS(Owl_Application);

PHP_METHOD(Owl_Application, getRequest);
PHP_METHOD(Owl_Application, getResponse);
PHP_METHOD(Owl_Application, bootstrap);
PHP_METHOD(Owl_Application, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_application_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Owl\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, response, Owl\\Http\\Response, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_application_method_entry) {
	PHP_ME(Owl_Application, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, bootstrap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, handle, arginfo_owl_application_handle, ZEND_ACC_PUBLIC)
  PHP_FE_END
};