
extern zend_class_entry *owl_debug_profiler_ce;

ZEPHIR_INIT_CLASS(Owl_Debug_Profiler);

PHP_METHOD(Owl_Debug_Profiler, __construct);
PHP_METHOD(Owl_Debug_Profiler, logEvent);
PHP_METHOD(Owl_Debug_Profiler, listen);
PHP_METHOD(Owl_Debug_Profiler, show);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_debug_profiler_logevent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, event, Owl\\Event\\Event, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_debug_profiler_listen, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, em, Owl\\Event\\Manager, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_debug_profiler_method_entry) {
	PHP_ME(Owl_Debug_Profiler, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Debug_Profiler, logEvent, arginfo_owl_debug_profiler_logevent, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Debug_Profiler, listen, arginfo_owl_debug_profiler_listen, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Debug_Profiler, show, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
