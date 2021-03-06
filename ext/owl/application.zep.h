
extern zend_class_entry *owl_application_ce;

ZEPHIR_INIT_CLASS(Owl_Application);

PHP_METHOD(Owl_Application, getRequest);
PHP_METHOD(Owl_Application, getDi);
PHP_METHOD(Owl_Application, getEnv);
PHP_METHOD(Owl_Application, getDefaultNamespace);
PHP_METHOD(Owl_Application, setExceptionHandlerParameters);
PHP_METHOD(Owl_Application, getExceptionHandlerParameters);
PHP_METHOD(Owl_Application, setErrorHandlerParameters);
PHP_METHOD(Owl_Application, getErrorHandlerParameters);
PHP_METHOD(Owl_Application, __construct);
PHP_METHOD(Owl_Application, setDefaultNamespace);
PHP_METHOD(Owl_Application, dispatch);
PHP_METHOD(Owl_Application, handle);
static zend_object_value zephir_init_properties_Owl_Application(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_application_setexceptionhandlerparameters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, exceptionHandlerParameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_application_seterrorhandlerparameters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, errorHandlerParameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_application___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, di, Owl\\Di\\ContainerInterface, 1)
	ZEND_ARG_OBJ_INFO(0, eventManager, Owl\\Event\\Manager, 1)
	ZEND_ARG_INFO(0, env)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_application_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_application_dispatch, 0, 0, 2)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, callParameters)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_owl_application_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Owl\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Owl\\Http\\ResponseInterface, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(owl_application_method_entry) {
	PHP_ME(Owl_Application, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, getDi, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, getEnv, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, getDefaultNamespace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, setExceptionHandlerParameters, arginfo_owl_application_setexceptionhandlerparameters, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, getExceptionHandlerParameters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, setErrorHandlerParameters, arginfo_owl_application_seterrorhandlerparameters, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, getErrorHandlerParameters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, __construct, arginfo_owl_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Owl_Application, setDefaultNamespace, arginfo_owl_application_setdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, dispatch, arginfo_owl_application_dispatch, ZEND_ACC_PUBLIC)
	PHP_ME(Owl_Application, handle, arginfo_owl_application_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
