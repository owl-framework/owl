
extern zend_class_entry *owl_annotations_classannotationsresult_ce;

ZEPHIR_INIT_CLASS(Owl_Annotations_ClassAnnotationsResult);

PHP_METHOD(Owl_Annotations_ClassAnnotationsResult, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_annotations_classannotationsresult___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, annotations, 0)
	ZEND_ARG_ARRAY_INFO(0, methods, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_annotations_classannotationsresult_method_entry) {
	PHP_ME(Owl_Annotations_ClassAnnotationsResult, __construct, arginfo_owl_annotations_classannotationsresult___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
