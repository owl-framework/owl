
extern zend_class_entry *owl_console_application_ce;

ZEPHIR_INIT_CLASS(Owl_Console_Application);

PHP_METHOD(Owl_Console_Application, getCommands);
PHP_METHOD(Owl_Console_Application, addCommand);
PHP_METHOD(Owl_Console_Application, addCommands);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_console_application_addcommand, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, command, Owl\\Console\\CommandInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_console_application_addcommands, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, commands, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_console_application_method_entry) {
	PHP_ME(Owl_Console_Application, getCommands, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Console_Application, addCommand, arginfo_owl_console_application_addcommand, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Console_Application, addCommands, arginfo_owl_console_application_addcommands, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
