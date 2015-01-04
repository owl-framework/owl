
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
#include "kernel/concat.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_Router_Http_DynamicRoute) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Router\\Http, DynamicRoute, owl, router_http_dynamicroute, owl_router_route_ce, owl_router_http_dynamicroute_method_entry, 0);

	zend_declare_property_null(owl_router_http_dynamicroute_ce, SL("pattern"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Router_Http_DynamicRoute, getPattern) {

	zval *_0, *pattern, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pattern"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_MEMBER(this_ptr, "pattern");
	}
	pattern = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "`^", pattern, "$`u");
	zephir_update_property_this(this_ptr, SL("pattern"), _1 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "pattern");

}

PHP_METHOD(Owl_Router_Http_DynamicRoute, match) {

	zval *uri_param = NULL, *_0;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(_0, uri));

}

