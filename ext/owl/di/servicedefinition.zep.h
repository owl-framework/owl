
extern zend_class_entry *owl_di_servicedefinition_ce;

ZEPHIR_INIT_CLASS(Owl_Di_ServiceDefinition);

PHP_METHOD(Owl_Di_ServiceDefinition, getName);
PHP_METHOD(Owl_Di_ServiceDefinition, getDefinition);
PHP_METHOD(Owl_Di_ServiceDefinition, getShared);
PHP_METHOD(Owl_Di_ServiceDefinition, getResolved);
PHP_METHOD(Owl_Di_ServiceDefinition, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_servicedefinition___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_di_servicedefinition_method_entry) {
	PHP_ME(Owl_Di_ServiceDefinition, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Di_ServiceDefinition, getDefinition, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Di_ServiceDefinition, getShared, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Di_ServiceDefinition, getResolved, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Di_ServiceDefinition, __construct, arginfo_owl_di_servicedefinition___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_FE_END
};
