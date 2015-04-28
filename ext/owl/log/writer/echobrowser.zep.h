
extern zend_class_entry *owl_log_writer_echobrowser_ce;

ZEPHIR_INIT_CLASS(Owl_Log_Writer_EchoBrowser);

PHP_METHOD(Owl_Log_Writer_EchoBrowser, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_log_writer_echobrowser_write, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_log_writer_echobrowser_method_entry) {
	PHP_ME(Owl_Log_Writer_EchoBrowser, write, arginfo_owl_log_writer_echobrowser_write, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
