
extern zend_class_entry *owl_event_manager_ce;

ZEPHIR_INIT_CLASS(Owl_Event_Manager);

PHP_METHOD(Owl_Event_Manager, listen);
PHP_METHOD(Owl_Event_Manager, emit);
static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_event_manager_listen, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_event_manager_emit, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_event_manager_method_entry) {
	PHP_ME(Owl_Event_Manager, listen, arginfo_owl_event_manager_listen, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Event_Manager, emit, arginfo_owl_event_manager_emit, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
