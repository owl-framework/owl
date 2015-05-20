
extern zend_class_entry *owl_log_writerinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Log_WriterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_writerinterface_setformatter, 0, 0, 1)
	ZEND_ARG_INFO(0, formatter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_writerinterface_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_writerinterface_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_writerinterface_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_writerinterface_setlevels, 0, 0, 1)
	ZEND_ARG_INFO(0, levels)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_writerinterface_commit, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, records, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_writerinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Log_WriterInterface, setFormatter, arginfo_owl_log_writerinterface_setformatter)
	PHP_ABSTRACT_ME(Owl_Log_WriterInterface, getFormatter, NULL)
	PHP_ABSTRACT_ME(Owl_Log_WriterInterface, setOptions, arginfo_owl_log_writerinterface_setoptions)
	PHP_ABSTRACT_ME(Owl_Log_WriterInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Owl_Log_WriterInterface, setOption, arginfo_owl_log_writerinterface_setoption)
	PHP_ABSTRACT_ME(Owl_Log_WriterInterface, getOption, arginfo_owl_log_writerinterface_getoption)
	PHP_ABSTRACT_ME(Owl_Log_WriterInterface, setLevels, arginfo_owl_log_writerinterface_setlevels)
	PHP_ABSTRACT_ME(Owl_Log_WriterInterface, getLevels, NULL)
	PHP_ABSTRACT_ME(Owl_Log_WriterInterface, commit, arginfo_owl_log_writerinterface_commit)
	PHP_ABSTRACT_ME(Owl_Log_WriterInterface, push, NULL)
  PHP_FE_END
};
