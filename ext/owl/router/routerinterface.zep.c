
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Router_RouterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Router, RouterInterface, owl, router_routerinterface, NULL);

	return SUCCESS;

}

