
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
#include "kernel/concat.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Owl_Log_Writer_File) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Log\\Writer, File, owl, log_writer_file, owl_log_abstractwriter_ce, owl_log_writer_file_method_entry, 0);

	return SUCCESS;

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_Writer_File, write) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *record_param = NULL, *_0 = NULL, *_1 = NULL, *_2, _3;
	zval *record = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record_param);

	zephir_get_strval(record, record_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "logFile", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, record, _1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", &_4, 20, _0, _2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

