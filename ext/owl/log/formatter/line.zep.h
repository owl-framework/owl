
extern zend_class_entry *owl_log_formatter_line_ce;

ZEPHIR_INIT_CLASS(Owl_Log_Formatter_Line);

PHP_METHOD(Owl_Log_Formatter_Line, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_formatter_line_format, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Owl\\Log\\Record, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_formatter_line_method_entry) {
	PHP_ME(Owl_Log_Formatter_Line, format, arginfo_owl_log_formatter_line_format, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
