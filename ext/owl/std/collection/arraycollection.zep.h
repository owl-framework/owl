
extern zend_class_entry *owl_std_collection_arraycollection_ce;

ZEPHIR_INIT_CLASS(Owl_Std_Collection_ArrayCollection);

PHP_METHOD(Owl_Std_Collection_ArrayCollection, __construct);
PHP_METHOD(Owl_Std_Collection_ArrayCollection, add);
PHP_METHOD(Owl_Std_Collection_ArrayCollection, isEmpty);
PHP_METHOD(Owl_Std_Collection_ArrayCollection, map);
PHP_METHOD(Owl_Std_Collection_ArrayCollection, filter);
PHP_METHOD(Owl_Std_Collection_ArrayCollection, first);
PHP_METHOD(Owl_Std_Collection_ArrayCollection, last);
PHP_METHOD(Owl_Std_Collection_ArrayCollection, getIterator);
PHP_METHOD(Owl_Std_Collection_ArrayCollection, count);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_collection_arraycollection___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, elements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_collection_arraycollection_add, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_collection_arraycollection_map, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, func, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_collection_arraycollection_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_std_collection_arraycollection_method_entry) {
	PHP_ME(Owl_Std_Collection_ArrayCollection, __construct, arginfo_owl_std_collection_arraycollection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Std_Collection_ArrayCollection, add, arginfo_owl_std_collection_arraycollection_add, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_ArrayCollection, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_ArrayCollection, map, arginfo_owl_std_collection_arraycollection_map, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_ArrayCollection, filter, arginfo_owl_std_collection_arraycollection_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_ArrayCollection, first, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_ArrayCollection, last, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_ArrayCollection, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_Collection_ArrayCollection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
