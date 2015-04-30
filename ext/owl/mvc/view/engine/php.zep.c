
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Mvc_View_Engine_Php) {

	ZEPHIR_REGISTER_CLASS(Owl\\Mvc\\View\\Engine, Php, owl, mvc_view_engine_php, NULL, 0);

	return SUCCESS;

}

