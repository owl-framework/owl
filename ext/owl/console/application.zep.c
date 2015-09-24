
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Owl_Console_Application) {

	ZEPHIR_REGISTER_CLASS(Owl\\Console, Application, owl, console_application, owl_console_application_method_entry, 0);

	zend_declare_property_null(owl_console_application_ce, SL("commands"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Console_Application, getCommands) {


	RETURN_MEMBER(this_ptr, "commands");

}

PHP_METHOD(Owl_Console_Application, addCommand) {

	zval *command;

	zephir_fetch_params(0, 1, 0, &command);



	zephir_update_property_array_append(this_ptr, SL("commands"), command TSRMLS_CC);

}

PHP_METHOD(Owl_Console_Application, addCommands) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *commands_param = NULL, *command = NULL, **_2;
	zval *commands = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &commands_param);

	commands = commands_param;


	zephir_is_iterable(commands, &_1, &_0, 0, 0, "owl/Console/Application.zep", 22);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(command, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcommand", &_3, 0, command);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

