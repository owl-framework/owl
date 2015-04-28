
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
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_Log_Writer_EchoBrowser) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Log\\Writer, EchoBrowser, owl, log_writer_echobrowser, owl_log_abstractwriter_ce, owl_log_writer_echobrowser_method_entry, 0);

	return SUCCESS;

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_Writer_EchoBrowser, write) {

	zval *record_param = NULL;
	zval *record = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record_param);

	zephir_get_strval(record, record_param);


	zend_print_zval(record, 0);
	ZEPHIR_MM_RESTORE();

}

