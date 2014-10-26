
extern zend_class_entry *owl_application_ce;

ZEPHIR_INIT_CLASS(Owl_Application);

PHP_METHOD(Owl_Application, getRequest);
PHP_METHOD(Owl_Application, getResponse);
PHP_METHOD(Owl_Application, bootstrap);
PHP_METHOD(Owl_Application, run);

ZEPHIR_INIT_FUNCS(owl_application_method_entry) {
	PHP_ME(Owl_Application, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, bootstrap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, run, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
