
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


ZEPHIR_INIT_CLASS(Owl_Router_Route) {

	ZEPHIR_REGISTER_CLASS(Owl\\Router, Route, owl, router_route, NULL, 0);

	zend_declare_property_null(owl_router_route_ce, SL("uri"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(owl_router_route_ce, SL("method"), "GET", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(owl_router_route_ce, SL("parameters"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

