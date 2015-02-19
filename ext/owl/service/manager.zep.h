
extern zend_class_entry *owl_service_manager_ce;

ZEPHIR_INIT_CLASS(Owl_Service_Manager);

PHP_METHOD(Owl_Service_Manager, setService);
PHP_METHOD(Owl_Service_Manager, get);
PHP_METHOD(Owl_Service_Manager, getInstance);
PHP_METHOD(Owl_Service_Manager, getService);
PHP_METHOD(Owl_Service_Manager, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_service_manager_setservice, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_service_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_service_manager_getinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_service_manager_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_service_manager_method_entry) {
	PHP_ME(Owl_Service_Manager, setService, arginfo_owl_service_manager_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Service_Manager, get, arginfo_owl_service_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Service_Manager, getInstance, arginfo_owl_service_manager_getinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Service_Manager, getService, arginfo_owl_service_manager_getservice, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Service_Manager, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
