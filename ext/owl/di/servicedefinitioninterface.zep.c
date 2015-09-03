
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Di_ServiceDefinitionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Di, ServiceDefinitionInterface, owl, di_servicedefinitioninterface, NULL);

	return SUCCESS;

}

