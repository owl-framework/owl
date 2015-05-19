
extern zend_class_entry *owl_log_abstractwriter_ce;

ZEPHIR_INIT_CLASS(Owl_Log_AbstractWriter);

PHP_METHOD(Owl_Log_AbstractWriter, getLevels);
PHP_METHOD(Owl_Log_AbstractWriter, setLevels);
PHP_METHOD(Owl_Log_AbstractWriter, getRecords);
PHP_METHOD(Owl_Log_AbstractWriter, getOptions);
PHP_METHOD(Owl_Log_AbstractWriter, setOptions);
PHP_METHOD(Owl_Log_AbstractWriter, getRecordsInterval);
PHP_METHOD(Owl_Log_AbstractWriter, setRecordsInterval);
PHP_METHOD(Owl_Log_AbstractWriter, __destruct);
PHP_METHOD(Owl_Log_AbstractWriter, setOption);
PHP_METHOD(Owl_Log_AbstractWriter, getOption);
PHP_METHOD(Owl_Log_AbstractWriter, defaultFormatter);
PHP_METHOD(Owl_Log_AbstractWriter, getFormatter);
PHP_METHOD(Owl_Log_AbstractWriter, setFormatter);
PHP_METHOD(Owl_Log_AbstractWriter, format);
PHP_METHOD(Owl_Log_AbstractWriter, filterRecords);
PHP_METHOD(Owl_Log_AbstractWriter, commit);
PHP_METHOD(Owl_Log_AbstractWriter, push);
PHP_METHOD(Owl_Log_AbstractWriter, write);
PHP_METHOD(Owl_Log_AbstractWriter, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractwriter_setlevels, 0, 0, 1)
	ZEND_ARG_INFO(0, levels)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractwriter_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractwriter_setrecordsinterval, 0, 0, 1)
	ZEND_ARG_INFO(0, recordsInterval)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractwriter_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractwriter_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractwriter_setformatter, 0, 0, 1)
	ZEND_ARG_INFO(0, formatter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractwriter_format, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Owl\\Log\\Record, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractwriter_filterrecords, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, records, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractwriter_commit, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, records, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_abstractwriter_write, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_abstractwriter_method_entry) {
	PHP_ME(Owl_Log_AbstractWriter, getLevels, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, setLevels, arginfo_owl_log_abstractwriter_setlevels, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, getRecords, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, setOptions, arginfo_owl_log_abstractwriter_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, getRecordsInterval, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, setRecordsInterval, arginfo_owl_log_abstractwriter_setrecordsinterval, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Owl_Log_AbstractWriter, setOption, arginfo_owl_log_abstractwriter_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, getOption, arginfo_owl_log_abstractwriter_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, defaultFormatter, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Owl_Log_AbstractWriter, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, setFormatter, arginfo_owl_log_abstractwriter_setformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, format, arginfo_owl_log_abstractwriter_format, ZEND_ACC_PROTECTED)
	PHP_ME(Owl_Log_AbstractWriter, filterRecords, arginfo_owl_log_abstractwriter_filterrecords, ZEND_ACC_PROTECTED)
	PHP_ME(Owl_Log_AbstractWriter, commit, arginfo_owl_log_abstractwriter_commit, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, push, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Log_AbstractWriter, write, arginfo_owl_log_abstractwriter_write, ZEND_ACC_PROTECTED)
	PHP_ME(Owl_Log_AbstractWriter, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
