
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Di_ServiceDefinition) {

	ZEPHIR_REGISTER_CLASS(Owl\\Di, ServiceDefinition, owl, di_servicedefinition, NULL, 0);

	zend_class_implements(owl_di_servicedefinition_ce TSRMLS_CC, 1, owl_di_servicedefinitioninterface_ce);
	return SUCCESS;

}

