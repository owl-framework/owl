
extern zend_class_entry *owl_std_collection_abstractcollection_ce;

ZEPHIR_INIT_CLASS(Owl_Std_Collection_AbstractCollection);

PHP_METHOD(Owl_Std_Collection_AbstractCollection, count);
PHP_METHOD(Owl_Std_Collection_AbstractCollection, getIterator);
PHP_METHOD(Owl_Std_Collection_AbstractCollection, map);
PHP_METHOD(Owl_Std_Collection_AbstractCollection, filter);
PHP_METHOD(Owl_Std_Collection_AbstractCollection, first);
PHP_METHOD(Owl_Std_Collection_AbstractCollection, last);
PHP_METHOD(Owl_Std_Collection_AbstractCollection, add);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_collection_abstractcollection_map, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, func, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_collection_abstractcollection_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_collection_abstractcollection_add, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_std_collection_abstractcollection_method_entry) {
	PHP_ME(Owl_Std_Collection_AbstractCollection, count, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_AbstractCollection, getIterator, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_AbstractCollection, map, arginfo_owl_std_collection_abstractcollection_map, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_AbstractCollection, filter, arginfo_owl_std_collection_abstractcollection_filter, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_AbstractCollection, first, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_AbstractCollection, last, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_AbstractCollection, add, arginfo_owl_std_collection_abstractcollection_add, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
