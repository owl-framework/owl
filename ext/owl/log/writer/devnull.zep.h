
extern zend_class_entry *owl_log_writer_devnull_ce;

ZEPHIR_INIT_CLASS(Owl_Log_Writer_DevNull);

PHP_METHOD(Owl_Log_Writer_DevNull, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_writer_devnull_write, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_writer_devnull_method_entry) {
	PHP_ME(Owl_Log_Writer_DevNull, write, arginfo_owl_log_writer_devnull_write, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
