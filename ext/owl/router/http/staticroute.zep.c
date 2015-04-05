
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_Router_Http_StaticRoute) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Router\\Http, StaticRoute, owl, router_http_staticroute, owl_router_route_ce, owl_router_http_staticroute_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Router_Http_StaticRoute, __construct) {

	zval *uri_param = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	zephir_update_property_this(this_ptr, SL("uri"), uri TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Router_Http_StaticRoute, match) {

	zval *uri_param = NULL, *_0;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(_0, uri));

}

