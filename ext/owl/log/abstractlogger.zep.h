
extern zend_class_entry *owl_log_abstractlogger_ce;

ZEPHIR_INIT_CLASS(Owl_Log_AbstractLogger);

PHP_METHOD(Owl_Log_AbstractLogger, getLevelTitle);
PHP_METHOD(Owl_Log_AbstractLogger, emergency);
PHP_METHOD(Owl_Log_AbstractLogger, alert);
PHP_METHOD(Owl_Log_AbstractLogger, critical);
PHP_METHOD(Owl_Log_AbstractLogger, error);
PHP_METHOD(Owl_Log_AbstractLogger, warning);
PHP_METHOD(Owl_Log_AbstractLogger, notice);
PHP_METHOD(Owl_Log_AbstractLogger, info);
PHP_METHOD(Owl_Log_AbstractLogger, debug);
PHP_METHOD(Owl_Log_AbstractLogger, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractlogger_getleveltitle, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractlogger_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractlogger_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractlogger_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractlogger_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractlogger_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractlogger_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractlogger_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractlogger_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractlogger_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_abstractlogger_method_entry) {
	PHP_ME(Owl_Log_AbstractLogger, getLevelTitle, arginfo_owl_log_abstractlogger_getleveltitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Owl_Log_AbstractLogger, emergency, arginfo_owl_log_abstractlogger_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractLogger, alert, arginfo_owl_log_abstractlogger_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractLogger, critical, arginfo_owl_log_abstractlogger_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractLogger, error, arginfo_owl_log_abstractlogger_error, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractLogger, warning, arginfo_owl_log_abstractlogger_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractLogger, notice, arginfo_owl_log_abstractlogger_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractLogger, info, arginfo_owl_log_abstractlogger_info, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractLogger, debug, arginfo_owl_log_abstractlogger_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractLogger, log, arginfo_owl_log_abstractlogger_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
