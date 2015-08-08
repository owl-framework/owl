
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
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Owl_Filter_Email) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Filter, Email, owl, filter_email, owl_filter_abstractfilter_ce, owl_filter_email_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Filter_Email, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 517);
	ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 17, value, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

