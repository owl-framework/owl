
extern zend_class_entry *owl_annotations_parser_ce;

ZEPHIR_INIT_CLASS(Owl_Annotations_Parser);

PHP_METHOD(Owl_Annotations_Parser, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_annotations_parser_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, comment)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_annotations_parser_method_entry) {
	PHP_ME(Owl_Annotations_Parser, parse, arginfo_owl_annotations_parser_parse, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
