
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Log_LoggerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Log, LoggerInterface, owl, log_loggerinterface, owl_log_loggerinterface_method_entry);

	return SUCCESS;

}

/**
 * System is unusable.
 */
ZEPHIR_DOC_METHOD(Owl_Log_LoggerInterface, emergency);

/**
 * Action must be taken immediately.
 *
 * Example: Entire website down, database unavailable, etc. This should
 * trigger the SMS alerts and wake you up.
 */
ZEPHIR_DOC_METHOD(Owl_Log_LoggerInterface, alert);

/**
 * Critical conditions.
 *
 * Example: Application component unavailable, unexpected exception.
 */
ZEPHIR_DOC_METHOD(Owl_Log_LoggerInterface, critical);

/**
 * Runtime errors that do not require immediate action but should typically
 * be logged and monitored.
 */
ZEPHIR_DOC_METHOD(Owl_Log_LoggerInterface, error);

/**
 * Exceptional occurrences that are not errors.
 *
 * Example: Use of deprecated APIs, poor use of an API, undesirable things
 * that are not necessarily wrong.
 */
ZEPHIR_DOC_METHOD(Owl_Log_LoggerInterface, warning);

/**
 * Normal but significant events.
 */
ZEPHIR_DOC_METHOD(Owl_Log_LoggerInterface, notice);

/**
 * Interesting events.
 *
 * Example: User logs in, SQL logs.
 */
ZEPHIR_DOC_METHOD(Owl_Log_LoggerInterface, info);

/**
 * Detailed debug information.
 */
ZEPHIR_DOC_METHOD(Owl_Log_LoggerInterface, debug);

/**
 * Logs with an arbitrary level.
 */
ZEPHIR_DOC_METHOD(Owl_Log_LoggerInterface, log);

