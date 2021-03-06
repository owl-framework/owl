
extern zend_class_entry *owl_log_record_ce;

ZEPHIR_INIT_CLASS(Owl_Log_Record);

PHP_METHOD(Owl_Log_Record, interpolate);
PHP_METHOD(Owl_Log_Record, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_record_interpolate, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_record___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_record_method_entry) {
	PHP_ME(Owl_Log_Record, interpolate, arginfo_owl_log_record_interpolate, ZEND_ACC_PROTECTED)
	PHP_ME(Owl_Log_Record, __construct, arginfo_owl_log_record___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
