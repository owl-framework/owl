
extern zend_class_entry *owl_log_abstractformatter_ce;

ZEPHIR_INIT_CLASS(Owl_Log_AbstractFormatter);

PHP_METHOD(Owl_Log_AbstractFormatter, interpolate);
PHP_METHOD(Owl_Log_AbstractFormatter, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractformatter_interpolate, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractformatter_format, 0, 0, 3)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_abstractformatter_method_entry) {
	PHP_ME(Owl_Log_AbstractFormatter, interpolate, arginfo_owl_log_abstractformatter_interpolate, ZEND_ACC_PROTECTED)
	PHP_ME(Owl_Log_AbstractFormatter, format, arginfo_owl_log_abstractformatter_format, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
