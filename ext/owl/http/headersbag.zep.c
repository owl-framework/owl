
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


ZEPHIR_INIT_CLASS(Owl_Http_HeadersBag) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Http, HeadersBag, owl, http_headersbag, owl_std_arraybag_ce, NULL, 0);

	return SUCCESS;

}

