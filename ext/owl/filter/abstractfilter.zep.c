
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


ZEPHIR_INIT_CLASS(Owl_Filter_AbstractFilter) {

	ZEPHIR_REGISTER_CLASS(Owl\\Filter, AbstractFilter, owl, filter_abstractfilter, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(owl_filter_abstractfilter_ce TSRMLS_CC, 1, owl_filter_filterinterface_ce);
	return SUCCESS;

}

