
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Session_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Session, ManagerInterface, owl, session_managerinterface, owl_session_managerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Owl_Session_ManagerInterface, start);

ZEPHIR_DOC_METHOD(Owl_Session_ManagerInterface, getId);

ZEPHIR_DOC_METHOD(Owl_Session_ManagerInterface, rememberMe);

ZEPHIR_DOC_METHOD(Owl_Session_ManagerInterface, forgetMe);

