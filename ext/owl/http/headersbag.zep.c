
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
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Owl_Http_HeadersBag) {

	ZEPHIR_REGISTER_CLASS_EX(Owl\\Http, HeadersBag, owl, http_headersbag, owl_std_arraybag_ce, owl_http_headersbag_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Owl_Http_HeadersBag, send) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *header = NULL, *value = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "owl/Http/HeadersBag.zep", 19);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(header, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (!(ZEPHIR_IS_EMPTY(value))) {
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_VSV(_4, header, ": ", value);
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_5, 18, _4, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_5, 18, header, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

