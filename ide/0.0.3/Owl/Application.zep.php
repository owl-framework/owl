<?php

namespace Owl;

class Application implements \Owl\ApplicationInterface
{
    /**
     * Latest Request
     *
     * @var \Owl\Http\RequestInterface
     */
    protected $request;

    /**
     * @var \Owl\Service\Manager
     */
    protected $di;

    /**
     * Current env, see ENV_* constants
     *
     * @var string
     */
    protected $env;

    /**
     * Count for dispatches
     */
    protected $currentLoop = 0;

    /**
     * @var \Owl\Event\Manager
     */
    protected $eventManager;

    /**
     * Handle parameters for exception catch
     *
     * @var array
     */
    protected $exceptionHandlerParameters = array("module" => "Api", "controller" => "Index", "action" => "exception");


    /**
     * Latest Request
     *
     * @return \Owl\Http\RequestInterface 
     */
    public function getRequest() {}

    /**
     * @return \Owl\Service\Manager 
     */
    public function getDi() {}

    /**
     * Current env, see ENV_* constants
     *
     * @return string 
     */
    public function getEnv() {}

    /**
     * Handle parameters for exception catch
     *
     * @param array $exceptionHandlerParameters 
     */
    public function setExceptionHandlerParameters($exceptionHandlerParameters) {}

    /**
     * Handle parameters for exception catch
     *
     * @return array 
     */
    public function getExceptionHandlerParameters() {}

    /**
     * @param mixed $di 
     * @param mixed $eventManager 
     * @param string $env 
     */
    public function __construct(\Owl\Service\Manager $di = null, Event\Manager $eventManager = null, $env = ApplicationInterface::ENV_PRODUCTION) {}

    /**
     * Dispatch the action
     *
     * @param mixed $parameters 
     * @param mixed $matchedRoute 
     * @param mixed $response 
     */
    protected function dispatch($parameters, $matchedRoute, $response) {}

    /**
     * Handle Http Request
     *
     * @param mixed $request 
     * @param mixed $response 
     * @return \Owl\Http\ResponseInterface 
     */
    public function handle(\Owl\Http\RequestInterface $request, \Owl\Http\ResponseInterface $response = null) {}

}
