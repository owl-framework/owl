
extern zend_class_entry *owl_event_event_ce;

ZEPHIR_INIT_CLASS(Owl_Event_Event);

PHP_METHOD(Owl_Event_Event, getName);
PHP_METHOD(Owl_Event_Event, getData);
PHP_METHOD(Owl_Event_Event, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_event_event___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_event_event_method_entry) {
	PHP_ME(Owl_Event_Event, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Event_Event, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Event_Event, __construct, arginfo_owl_event_event___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
