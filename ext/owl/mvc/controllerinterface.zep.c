
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Mvc_ControllerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Mvc, ControllerInterface, owl, mvc_controllerinterface, owl_mvc_controllerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Owl_Mvc_ControllerInterface, __construct);

