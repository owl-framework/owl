
extern zend_class_entry *owl_debug_memoryprofiler_ce;

ZEPHIR_INIT_CLASS(Owl_Debug_MemoryProfiler);

PHP_METHOD(Owl_Debug_MemoryProfiler, getPlatformInfo);
PHP_METHOD(Owl_Debug_MemoryProfiler, objectsList);

ZEPHIR_INIT_FUNCS(owl_debug_memoryprofiler_method_entry) {
	PHP_ME(Owl_Debug_MemoryProfiler, getPlatformInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Debug_MemoryProfiler, objectsList, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
