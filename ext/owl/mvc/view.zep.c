
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
#include "kernel/memory.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Owl_Mvc_View) {

	ZEPHIR_REGISTER_CLASS(Owl\\Mvc, View, owl, mvc_view, owl_mvc_view_method_entry, 0);

	/**
	 * Base path for views
	 */
	zend_declare_property_string(owl_mvc_view_ce, SL("path"), "./../resources/views/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(owl_mvc_view_ce TSRMLS_CC, 1, owl_mvc_viewinterface_ce);
	return SUCCESS;

}

/**
 * Base path for views
 */
PHP_METHOD(Owl_Mvc_View, getPath) {


	RETURN_MEMBER(this_ptr, "path");

}

/**
 * Base path for views
 */
PHP_METHOD(Owl_Mvc_View, setPath) {

	zval *path;

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_this(this_ptr, SL("path"), path TSRMLS_CC);

}

/**
 * Render view
 */
PHP_METHOD(Owl_Mvc_View, render) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL;
	zval *path_param = NULL, *parameters_param = NULL, *_0, *_1, *_2, *_3, *_4 = NULL, *_5, *_6, *_7, *tmp = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &parameters_param);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, path);
	if (!((zephir_file_exists(_1 TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(owl_exception_ce, "File is not exists", "owl/Mvc/View.zep", 21);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, path);
	ZEPHIR_CALL_FUNCTION(&_4, "is_readable", NULL, 27, _3);
	zephir_check_call_status();
	if (!(zephir_is_true(_4))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(owl_exception_ce, "File is not readable", "owl/Mvc/View.zep", 25);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 28);
	zephir_check_call_status();
	if (!(Z_TYPE_P(parameters) == IS_NULL)) {
		ZEPHIR_INIT_VAR(_5);
		ZVAL_LONG(_5, 0);
		ZEPHIR_MAKE_REF(parameters);
		ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 29, parameters, _5);
		ZEPHIR_UNREF(parameters);
		zephir_check_call_status();
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_VV(_7, _6, path);
	if (zephir_require_zval(_7 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&tmp, "ob_get_contents", NULL, 30);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 31);
	zephir_check_call_status();
	RETURN_CCTOR(tmp);

}

