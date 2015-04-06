<?php

namespace Owl\Mvc;

class Controller
{
    /**
     * @var \Owl\Http\RequestInterface
     */
    protected $request;

    /**
     * @var \Owl\Http\ResponseInterface
     */
    protected $response;

    /**
     * @var \Owl\Service\Manager
     */
    protected $di;


    /**
     * @return \Owl\Http\RequestInterface 
     */
	public function getRequest() {}

    /**
     * @return \Owl\Http\ResponseInterface 
     */
	public function getResponse() {}

    /**
     * @return \Owl\Service\Manager 
     */
	public function getDi() {}

    /**
     * @param mixed $request 
     * @param mixed $response 
     * @param mixed $di 
     */
	public function __construct(\Owl\Http\Request $request, \Owl\Http\Response $response, \Owl\Service\Manager $di) {}

}
