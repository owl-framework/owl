
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Http_RequestInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Http, RequestInterface, owl, http_requestinterface, owl_http_requestinterface_method_entry);

	return SUCCESS;

}

/**
 * Get Request's URI
 */
ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getUri);

/**
 * Get Request's path (URI without GET parameters)
 */
ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getPath);

ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getParam);

ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getPost);

ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getServer);

ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getScheme);

ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getMethod);

