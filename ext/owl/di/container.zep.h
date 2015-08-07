
extern zend_class_entry *owl_di_container_ce;

ZEPHIR_INIT_CLASS(Owl_Di_Container);

PHP_METHOD(Owl_Di_Container, setService);
PHP_METHOD(Owl_Di_Container, set);
PHP_METHOD(Owl_Di_Container, has);
PHP_METHOD(Owl_Di_Container, get);
PHP_METHOD(Owl_Di_Container, getService);
static zend_object_value zephir_init_properties_Owl_Di_Container(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_container_setservice, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_container_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_container_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_container_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_di_container_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_di_container_method_entry) {
	PHP_ME(Owl_Di_Container, setService, arginfo_owl_di_container_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Di_Container, set, arginfo_owl_di_container_set, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Di_Container, has, arginfo_owl_di_container_has, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Di_Container, get, arginfo_owl_di_container_get, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Di_Container, getService, arginfo_owl_di_container_getservice, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
