
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Di_ContainerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Di, ContainerInterface, owl, di_containerinterface, owl_di_containerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Owl_Di_ContainerInterface, setService);

ZEPHIR_DOC_METHOD(Owl_Di_ContainerInterface, set);

ZEPHIR_DOC_METHOD(Owl_Di_ContainerInterface, has);

ZEPHIR_DOC_METHOD(Owl_Di_ContainerInterface, get);

ZEPHIR_DOC_METHOD(Owl_Di_ContainerInterface, getService);

