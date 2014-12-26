
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Bridge_Lynx_Rest_EntityController) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Bridge\\Lynx\\Rest, EntityController, owl, bridge_lynx_rest_entitycontroller, owl_mvc_controller_ce, owl_bridge_lynx_rest_entitycontroller_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Bridge_Lynx_Rest_EntityController, getAction) {



}

PHP_METHOD(Owl_Bridge_Lynx_Rest_EntityController, deleteAction) {



}

PHP_METHOD(Owl_Bridge_Lynx_Rest_EntityController, createAction) {



}

