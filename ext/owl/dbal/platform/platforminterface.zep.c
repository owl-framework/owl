
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_DBAL_Platform_PlatformInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\DBAL\\Platform, PlatformInterface, owl, dbal_platform_platforminterface, owl_dbal_platform_platforminterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Owl_DBAL_Platform_PlatformInterface, wrap);

