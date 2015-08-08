
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Owl_Log_Formatter_Json) {

	ZEPHIR_REGISTER_CLASS(Owl\\Log\\Formatter, Json, owl, log_formatter_json, owl_log_formatter_json_method_entry, 0);

	zend_class_implements(owl_log_formatter_json_ce TSRMLS_CC, 1, owl_log_formatterinterface_ce);
	return SUCCESS;

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_Formatter_Json, format) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *_0;
	zval *record, *_1 = NULL, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, record, SL("level"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_1, owl_log_logger_ce, "getleveltitle", &_2, 21, _3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("type"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, record, SL("message"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("message"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_4);
	zephir_read_property(&_4, record, SL("timestamp"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("timestamp"), &_4, PH_COPY | PH_SEPARATE);
	zephir_json_encode(return_value, &(return_value), _0, 0  TSRMLS_CC);
	RETURN_MM();

}

