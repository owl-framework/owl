<?php

namespace Owl;

class Application
{

    protected $request;

    protected $response;

    protected $di;


	public function getRequest() {}


	public function getResponse() {}


	public function getDi() {}

    /**
     * @param mixed $di 
     */
	public function __construct($di = null) {}


	public function bootstrap() {}

    /**
     * @param mixed $request 
     * @param mixed $response 
     * @return Http\Response 
     */
	public function handle(Http\Request $request, Http\Response $response = null) {}

}
