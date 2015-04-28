
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Log_FormatterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Log, FormatterInterface, owl, log_formatterinterface, owl_log_formatterinterface_method_entry);

	return SUCCESS;

}

/**
 * Format record
 */
ZEPHIR_DOC_METHOD(Owl_Log_FormatterInterface, format);

