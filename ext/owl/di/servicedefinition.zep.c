
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
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Owl_Di_ServiceDefinition) {

	ZEPHIR_REGISTER_CLASS(Owl\\Di, ServiceDefinition, owl, di_servicedefinition, owl_di_servicedefinition_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(owl_di_servicedefinition_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var object|callable
	 */
	zend_declare_property_null(owl_di_servicedefinition_ce, SL("definition"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean
	 */
	zend_declare_property_bool(owl_di_servicedefinition_ce, SL("shared"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean
	 */
	zend_declare_property_bool(owl_di_servicedefinition_ce, SL("resolved"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(owl_di_servicedefinition_ce TSRMLS_CC, 1, owl_di_servicedefinitioninterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Owl_Di_ServiceDefinition, getName) {


	RETURN_MEMBER(this_ptr, "name");

}

/**
 */
PHP_METHOD(Owl_Di_ServiceDefinition, getDefinition) {


	RETURN_MEMBER(this_ptr, "definition");

}

/**
 */
PHP_METHOD(Owl_Di_ServiceDefinition, getShared) {


	RETURN_MEMBER(this_ptr, "shared");

}

/**
 */
PHP_METHOD(Owl_Di_ServiceDefinition, getResolved) {


	RETURN_MEMBER(this_ptr, "resolved");

}

/**
 * Phalcon\Di\Service
 *
 * @param string name
 * @param mixed definition
 * @param boolean shared
 */
PHP_METHOD(Owl_Di_ServiceDefinition, __construct) {

	zend_bool shared;
	zval *name_param = NULL, *definition, *shared_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &definition, &shared_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("definition"), definition TSRMLS_CC);
	if (shared) {
		zephir_update_property_this(this_ptr, SL("shared"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("shared"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

