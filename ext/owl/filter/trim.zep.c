
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
#include "kernel/string.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_Filter_Trim) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Filter, Trim, owl, filter_trim, owl_filter_abstractfilter_ce, owl_filter_trim_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Filter_Trim, filter) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_fast_trim(return_value, value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	return;

}

