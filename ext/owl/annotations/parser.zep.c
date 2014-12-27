
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
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Owl_Annotations_Parser) {

	ZEPHIR_REGISTER_CLASS(Owl\\Annotations, Parser, owl, annotations_parser, owl_annotations_parser_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Annotations_Parser, parser) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *comment_param = NULL, *_0, *_1;
	zval *comment = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &comment_param);

	zephir_get_strval(comment, comment_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_RETURN_CALL_FUNCTION("parse_annotations", NULL, comment, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

