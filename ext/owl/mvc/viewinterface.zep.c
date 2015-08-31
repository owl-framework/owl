
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Mvc_ViewInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Mvc, ViewInterface, owl, mvc_viewinterface, owl_mvc_viewinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Owl_Mvc_ViewInterface, getPath);

/**
 * Render view
 */
ZEPHIR_DOC_METHOD(Owl_Mvc_ViewInterface, render);

