
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
#include "ext/spl/spl_iterators.h"


ZEPHIR_INIT_CLASS(Owl_Std_Collection_AbstractCollection) {

	ZEPHIR_REGISTER_CLASS(Owl\\Std\\Collection, AbstractCollection, owl, std_collection_abstractcollection, owl_std_collection_abstractcollection_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(owl_std_collection_abstractcollection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(owl_std_collection_abstractcollection_ce TSRMLS_CC, 1, zend_ce_aggregate);
	return SUCCESS;

}

/**
 * Get elements count from a collection
 */
PHP_METHOD(Owl_Std_Collection_AbstractCollection, count) {

}

/**
 * Get iterator
 */
PHP_METHOD(Owl_Std_Collection_AbstractCollection, getIterator) {

}

/**
 * Execute a function on each element in the collection
 */
PHP_METHOD(Owl_Std_Collection_AbstractCollection, map) {

}

/**
 * Execute a function on each element in the collection and
 * removes the element from the collection if the executed function returns false
 */
PHP_METHOD(Owl_Std_Collection_AbstractCollection, filter) {

}

/**
 * Set the current element to the first element and returns it
 */
PHP_METHOD(Owl_Std_Collection_AbstractCollection, first) {

}

/**
 * Set current element to the last element and returns it
 */
PHP_METHOD(Owl_Std_Collection_AbstractCollection, last) {

}

/**
 * Add a element to the collection
 */
PHP_METHOD(Owl_Std_Collection_AbstractCollection, add) {

}

