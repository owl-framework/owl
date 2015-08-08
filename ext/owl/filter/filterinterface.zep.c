
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Filter_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Filter, FilterInterface, owl, filter_filterinterface, owl_filter_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the result of filtering $value
 */
ZEPHIR_DOC_METHOD(Owl_Filter_FilterInterface, filter);

