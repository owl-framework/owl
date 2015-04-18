
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Console_CommandInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Console, CommandInterface, owl, console_commandinterface, NULL);

	return SUCCESS;

}

