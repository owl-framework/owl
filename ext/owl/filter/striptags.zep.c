
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_Filter_StripTags) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Filter, StripTags, owl, filter_striptags, owl_filter_abstractfilter_ce, owl_filter_striptags_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Filter_StripTags, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_RETURN_CALL_FUNCTION("strip_tags", NULL, 18, value);
	zephir_check_call_status();
	RETURN_MM();

}

