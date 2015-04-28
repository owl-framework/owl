
extern zend_class_entry *owl_log_formatterinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Log_FormatterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_formatterinterface_format, 0, 0, 3)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_formatterinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Log_FormatterInterface, format, arginfo_owl_log_formatterinterface_format)
  PHP_FE_END
};
