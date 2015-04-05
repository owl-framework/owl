<?php

namespace Owl;

class Application
{

    const ENV_PRODUCTION = "production";


    const ENV_DEVELOPMENT = "development";

    /**
     * @var \Owl\Http\RequestInterface
     */
    protected $request;

    /**
     * @var \Owl\Http\Response
     */
    protected $response;

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
     * @return \Owl\Http\RequestInterface 
     */
	public function getRequest() {}

    /**
     * @return \Owl\Http\Response 
     */
	public function getResponse() {}

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
     * @param mixed $di 
     * @param string $env 
     */
	public function __construct(\Owl\Service\Manager $di = null, $env = self::ENV_PRODUCTION) {}

    /**
     * Handle Http Request
     *
     * @param mixed $request 
     * @param mixed $response 
     * @return \Owl\Http\Response 
     */
	public function handle(\Owl\Http\RequestInterface $request, \Owl\Http\Response $response = null) {}

}
