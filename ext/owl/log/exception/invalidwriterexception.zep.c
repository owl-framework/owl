
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
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Owl_Log_Exception_InvalidWriterException) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Log\\Exception, InvalidWriterException, owl, log_exception_invalidwriterexception, spl_ce_InvalidArgumentException, NULL, 0);

	return SUCCESS;

}

