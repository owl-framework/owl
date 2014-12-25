<?php

namespace Owl\Mvc;

class Controller
{

    protected $request;


	public function getRequest() {}

    /**
     * @param mixed $request 
     * @param mixed $response 
     */
	public function dispatch(\Owl\Http\Request $request, \Owl\Http\Response $response = null) {}

}
