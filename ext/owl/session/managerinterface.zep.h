
extern zend_class_entry *owl_session_managerinterface_ce;

ZEPHIR_INIT_CLASS(Owl_Session_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_session_managerinterface_rememberme, 0, 0, 1)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_session_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Owl_Session_ManagerInterface, start, NULL)
	PHP_ABSTRACT_ME(Owl_Session_ManagerInterface, getId, NULL)
	PHP_ABSTRACT_ME(Owl_Session_ManagerInterface, rememberMe, arginfo_owl_session_managerinterface_rememberme)
	PHP_ABSTRACT_ME(Owl_Session_ManagerInterface, forgetMe, NULL)
	PHP_FE_END
};
