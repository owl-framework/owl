
extern zend_class_entry *owl_annotations_reader_ce;

ZEPHIR_INIT_CLASS(Owl_Annotations_Reader);

PHP_METHOD(Owl_Annotations_Reader, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_annotations_reader_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, comment)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_annotations_reader_method_entry) {
	PHP_ME(Owl_Annotations_Reader, parse, arginfo_owl_annotations_reader_parse, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
