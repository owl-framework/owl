<?php

namespace Owl;

class Application
{

    protected $request;

    protected $response;


	public function getRequest() {}


	public function getResponse() {}


	public function bootstrap() {}

    /**
     * @param mixed $request 
     * @param mixed $response 
     * @return Http\Response 
     */
	public function handle($request, $response = null) {}

}
