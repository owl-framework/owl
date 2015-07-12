
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * Special writer for testing
 */
ZEPHIR_INIT_CLASS(Owl_Log_Writer_DevNull) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Log\\Writer, DevNull, owl, log_writer_devnull, owl_log_abstractwriter_ce, owl_log_writer_devnull_method_entry, 0);

	owl_log_writer_devnull_ce->create_object = zephir_init_properties_Owl_Log_Writer_DevNull;
	return SUCCESS;

}

/**
 * @inheritdoc
 */
PHP_METHOD(Owl_Log_Writer_DevNull, write) {

	zval *record_param = NULL;
	zval *record = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record_param);

	zephir_get_strval(record, record_param);


	RETURN_MM_NULL();

}

static zend_object_value zephir_init_properties_Owl_Log_Writer_DevNull(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2, *_3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("options"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("records"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("records"), _1 TSRMLS_CC);
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("levels"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("levels"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

