
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Log_WriterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Log, WriterInterface, owl, log_writerinterface, owl_log_writerinterface_method_entry);

	return SUCCESS;

}

/**
 * Set formatter for writer
 */
ZEPHIR_DOC_METHOD(Owl_Log_WriterInterface, setFormatter);

/**
 * Get formatter
 */
ZEPHIR_DOC_METHOD(Owl_Log_WriterInterface, getFormatter);

/**
 * Set options for writer
 */
ZEPHIR_DOC_METHOD(Owl_Log_WriterInterface, setOptions);

/**
 * Get options for writer
 */
ZEPHIR_DOC_METHOD(Owl_Log_WriterInterface, getOptions);

/**
 * Set option for writer
 */
ZEPHIR_DOC_METHOD(Owl_Log_WriterInterface, setOption);

/**
 * Get option for writer
 */
ZEPHIR_DOC_METHOD(Owl_Log_WriterInterface, getOption);

/**
 * Set message levels for writer
 */
ZEPHIR_DOC_METHOD(Owl_Log_WriterInterface, setLevels);

/**
 * Get message levels for writer
 */
ZEPHIR_DOC_METHOD(Owl_Log_WriterInterface, getLevels);

/**
 * Commit pack of messages
 */
ZEPHIR_DOC_METHOD(Owl_Log_WriterInterface, commit);

/**
 * Push all messages
 */
ZEPHIR_DOC_METHOD(Owl_Log_WriterInterface, push);

