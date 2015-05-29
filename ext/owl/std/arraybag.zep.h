
extern zend_class_entry *owl_std_arraybag_ce;

ZEPHIR_INIT_CLASS(Owl_Std_ArrayBag);

PHP_METHOD(Owl_Std_ArrayBag, __construct);
PHP_METHOD(Owl_Std_ArrayBag, count);
PHP_METHOD(Owl_Std_ArrayBag, set);
PHP_METHOD(Owl_Std_ArrayBag, has);
PHP_METHOD(Owl_Std_ArrayBag, get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_arraybag___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, input, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_arraybag_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_arraybag_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_std_arraybag_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_std_arraybag_method_entry) {
	PHP_ME(Owl_Std_ArrayBag, __construct, arginfo_owl_std_arraybag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Std_ArrayBag, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_ArrayBag, set, arginfo_owl_std_arraybag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_ArrayBag, has, arginfo_owl_std_arraybag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Std_ArrayBag, get, arginfo_owl_std_arraybag_get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
