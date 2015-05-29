
extern zend_class_entry *owl_log_logger_ce;

ZEPHIR_INIT_CLASS(Owl_Log_Logger);

PHP_METHOD(Owl_Log_Logger, getRecords);
PHP_METHOD(Owl_Log_Logger, getRecordsInterval);
PHP_METHOD(Owl_Log_Logger, setRecordsInterval);
PHP_METHOD(Owl_Log_Logger, getWriters);
PHP_METHOD(Owl_Log_Logger, __construct);
PHP_METHOD(Owl_Log_Logger, __destruct);
PHP_METHOD(Owl_Log_Logger, factoryWriter);
PHP_METHOD(Owl_Log_Logger, getWriter);
PHP_METHOD(Owl_Log_Logger, commit);
PHP_METHOD(Owl_Log_Logger, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_setrecordsinterval, 0, 0, 1)
	ZEND_ARG_INFO(0, recordsInterval)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, writers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_factorywriter, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, writerDescription, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_getwriter, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_logger_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_logger_method_entry) {
	PHP_ME(Owl_Log_Logger, getRecords, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, getRecordsInterval, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, setRecordsInterval, arginfo_owl_log_logger_setrecordsinterval, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, getWriters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, __construct, arginfo_owl_log_logger___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Log_Logger, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Owl_Log_Logger, factoryWriter, arginfo_owl_log_logger_factorywriter, ZEND_ACC_PROTECTED)
	PHP_ME(Owl_Log_Logger, getWriter, arginfo_owl_log_logger_getwriter, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_Logger, log, arginfo_owl_log_logger_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
