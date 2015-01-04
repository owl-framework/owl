
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_Annotations_ClassAnnotationsResult) {

	ZEPHIR_REGISTER_CLASS(Owl\\Annotations, ClassAnnotationsResult, owl, annotations_classannotationsresult, owl_annotations_classannotationsresult_method_entry, 0);

	zend_declare_property_null(owl_annotations_classannotationsresult_ce, SL("annotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(owl_annotations_classannotationsresult_ce, SL("methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Owl_Annotations_ClassAnnotationsResult, __construct) {

	zval *annotations_param = NULL, *methods_param = NULL;
	zval *annotations = NULL, *methods = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &annotations_param, &methods_param);

	annotations = annotations_param;

	if (!methods_param) {
	ZEPHIR_INIT_VAR(methods);
	array_init(methods);
	} else {
	methods = methods_param;

	}


	zephir_update_property_this(this_ptr, SL("annotations"), annotations TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("methods"), methods TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

