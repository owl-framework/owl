
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
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Owl_Mvc_View) {

	ZEPHIR_REGISTER_CLASS(Owl\\Mvc, View, owl, mvc_view, owl_mvc_view_method_entry, 0);

	/**
	 * Base path for views
	 */
	zend_declare_property_string(owl_mvc_view_ce, SL("path"), "./../resources/views/", ZEND_ACC_PROTECTED TSRMLS_CC);

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
	zval *path_param = NULL, *parameters_param = NULL, *_0, *_1, *_2, *_3, *_4, *tmp = NULL;
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
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 23);
	zephir_check_call_status();
	if (!(Z_TYPE_P(parameters) == IS_NULL)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 0);
		Z_SET_ISREF_P(parameters);
		ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 24, parameters, _2);
		Z_UNSET_ISREF_P(parameters);
		zephir_check_call_status();
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, _3, path);
	if (zephir_require_zval(_4 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&tmp, "ob_get_contents", NULL, 25);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 26);
	zephir_check_call_status();
	RETURN_CCTOR(tmp);

}

