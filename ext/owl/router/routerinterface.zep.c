
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Router_RouterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Router, RouterInterface, owl, router_routerinterface, owl_router_routerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Owl_Router_RouterInterface, matchRequest);

ZEPHIR_DOC_METHOD(Owl_Router_RouterInterface, match);

