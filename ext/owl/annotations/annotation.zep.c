
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


ZEPHIR_INIT_CLASS(Owl_Annotations_Annotation) {

	ZEPHIR_REGISTER_CLASS(Owl\\Annotations, Annotation, owl, annotations_annotation, NULL, 0);

	zend_declare_property_null(owl_annotations_annotation_ce, SL("value"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

