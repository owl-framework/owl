
extern zend_class_entry *owl_debug_profiler_ce;

ZEPHIR_INIT_CLASS(Owl_Debug_Profiler);

PHP_METHOD(Owl_Debug_Profiler, getAssetsUri);
PHP_METHOD(Owl_Debug_Profiler, setAssetsUri);
PHP_METHOD(Owl_Debug_Profiler, __construct);
PHP_METHOD(Owl_Debug_Profiler, logEvent);
PHP_METHOD(Owl_Debug_Profiler, listen);
PHP_METHOD(Owl_Debug_Profiler, setContent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_debug_profiler_setassetsuri, 0, 0, 1)
	ZEND_ARG_INFO(0, assetsUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_debug_profiler_logevent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, event, Owl\\Event\\Event, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_debug_profiler_listen, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, em, Owl\\Event\\Manager, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_debug_profiler_setcontent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Owl\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_debug_profiler_method_entry) {
	PHP_ME(Owl_Debug_Profiler, getAssetsUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Debug_Profiler, setAssetsUri, arginfo_owl_debug_profiler_setassetsuri, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Debug_Profiler, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Debug_Profiler, logEvent, arginfo_owl_debug_profiler_logevent, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Debug_Profiler, listen, arginfo_owl_debug_profiler_listen, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Debug_Profiler, setContent, arginfo_owl_debug_profiler_setcontent, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
