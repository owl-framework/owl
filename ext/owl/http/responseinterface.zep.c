
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Owl_Http_ResponseInterface) {

	ZEPHIR_REGISTER_INTERFACE(Owl\\Http, ResponseInterface, owl, http_responseinterface, owl_http_responseinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Owl_Http_ResponseInterface, send);

ZEPHIR_DOC_METHOD(Owl_Http_ResponseInterface, getContent);

ZEPHIR_DOC_METHOD(Owl_Http_ResponseInterface, setCode);

ZEPHIR_DOC_METHOD(Owl_Http_ResponseInterface, getCode);

