
extern zend_class_entry *owl_log_logger_ce;

ZEPHIR_INIT_CLASS(Owl_Log_Logger);

PHP_METHOD(Owl_Log_Logger, emergency);
PHP_METHOD(Owl_Log_Logger, alert);
PHP_METHOD(Owl_Log_Logger, critical);
PHP_METHOD(Owl_Log_Logger, error);
PHP_METHOD(Owl_Log_Logger, warning);
PHP_METHOD(Owl_Log_Logger, notice);
PHP_METHOD(Owl_Log_Logger, info);
PHP_METHOD(Owl_Log_Logger, debug);
PHP_METHOD(Owl_Log_Logger, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_logger_method_entry) {
	PHP_ME(Owl_Log_Logger, emergency, arginfo_owl_log_logger_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, alert, arginfo_owl_log_logger_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, critical, arginfo_owl_log_logger_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, error, arginfo_owl_log_logger_error, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, warning, arginfo_owl_log_logger_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, notice, arginfo_owl_log_logger_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, info, arginfo_owl_log_logger_info, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, debug, arginfo_owl_log_logger_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, log, arginfo_owl_log_logger_log, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
