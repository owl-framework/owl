
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

/**
 * Get parameter from $_GET
 */
ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getParam);

/**
 * Get parameter from $_POST
 */
ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getPost);

/**
 * Get parameter from $_SERVER
 */
ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getServer);

/**
 * Get Request's scheme (HTTP/HTTPS)
 */
ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getScheme);

/**
 * Get Request's method (GET, POST, PUT, DELETE, OPTIONS, HEAD, TRACE, CONNECT, PATCH, PROPFIND)
 */
ZEPHIR_DOC_METHOD(Owl_Http_RequestInterface, getMethod);

