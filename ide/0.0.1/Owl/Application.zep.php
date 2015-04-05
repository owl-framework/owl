<?php

namespace Owl;

class Application
{

    const ENV_PRODUCTION = "production";


    const ENV_DEVELOPMENT = "development";


    protected $request;


    protected $response;


    protected $di;


    protected $env;



	public function getRequest() {}


	public function getResponse() {}


	public function getDi() {}


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
