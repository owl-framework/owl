
extern zend_class_entry *owl_bridge_lynx_rest_entitycontroller_ce;

ZEPHIR_INIT_CLASS(Owl_Bridge_Lynx_Rest_EntityController);

PHP_METHOD(Owl_Bridge_Lynx_Rest_EntityController, getAction);
PHP_METHOD(Owl_Bridge_Lynx_Rest_EntityController, deleteAction);
PHP_METHOD(Owl_Bridge_Lynx_Rest_EntityController, createAction);

ZEPHIR_INIT_FUNCS(owl_bridge_lynx_rest_entitycontroller_method_entry) {
	PHP_ME(Owl_Bridge_Lynx_Rest_EntityController, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Bridge_Lynx_Rest_EntityController, deleteAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Bridge_Lynx_Rest_EntityController, createAction, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
