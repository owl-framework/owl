
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Owl_Log_Formatter_Line) {

	ZEPHIR_REGISTER_CLASS(Owl\\Log\\Formatter, Line, owl, log_formatter_line, owl_log_formatter_line_method_entry, 0);

	zend_class_implements(owl_log_formatter_line_ce TSRMLS_CC, 1, owl_log_formatterinterface_ce);
	return SUCCESS;

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_Formatter_Line, format) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *record, *_0 = NULL, *_2, *_3, _4, *_5 = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, record, SL("level"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, owl_log_logger_ce, "getleveltitle", &_1, 19, _2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, record, SL("timestamp"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "D, d M Y H:i:s O", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "date", NULL, 20, &_4, _3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property(&_6, record, SL("message"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VSVSV(return_value, _0, ":", _5, ":", _6);
	RETURN_MM();

}

