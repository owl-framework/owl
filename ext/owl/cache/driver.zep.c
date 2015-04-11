
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Cache_Driver) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Cache, Driver, owl, cache_driver, owl_cache_driver_method_entry);

	return SUCCESS;

}

/**
 * To initialize cache provider
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Owl_Cache_Driver, getInstance);

/**
 * Save data
 *
 * @param $id
 * @param $data
 * @param int $lifeTime
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Owl_Cache_Driver, save);

/**
 * Save data by id
 *
 * @param $id
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Owl_Cache_Driver, delete);

/**
 * Fetch data by id
 *
 * @param $id
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Owl_Cache_Driver, get);

/**
 * Is value exist?
 *
 * @param $id
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Owl_Cache_Driver, exists);

/**
 * Flush all values
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Owl_Cache_Driver, flush);

