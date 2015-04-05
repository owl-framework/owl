<?php

namespace Owl\Mvc;

class Controller
{
    /**
     * @var \Owl\Http\RequestInterface
     */
    protected $request;


    /**
     * @return \Owl\Http\RequestInterface 
     */
	public function getRequest() {}

    /**
     * @param mixed $request 
     * @param mixed $response 
     */
	public function __construct(\Owl\Http\Request $request, \Owl\Http\Response $response = null) {}

}
