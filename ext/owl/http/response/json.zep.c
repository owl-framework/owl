
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Owl_Http_Response_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Http\\Response, Json, owl, http_response_json, owl_http_response_ce, owl_http_response_json_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Http_Response_Json, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, owl_std_arraybag_ce);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("Content-Type"), SL("application/json"), 1);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_2, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("headers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Owl_Http_Response_Json, setContent) {

	zval *content, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	ZEPHIR_INIT_VAR(_0);
	zephir_json_encode(_0, &(_0), content, 0  TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("content"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

