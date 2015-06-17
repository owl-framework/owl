<?php

namespace Owl\Router;


class Router implements \Owl\Router\RouterInterface
{

    protected $basePath = "";


    protected $routers = array();



    public function getBasePath() {}

    /**
     * @param mixed $basePath 
     */
    public function setBasePath($basePath) {}

    /**
     * @param string $uri 
     * @param array $parameters 
     * @param string $method 
     */
    public function add($uri, $parameters = array(), $method = Request::GET) {}

    /**
     * @param mixed $route 
     */
    public function addRoute(Route $route) {}

    /**
     * @param mixed $request 
     */
    public function matchRequest(\Owl\Http\RequestInterface $request) {}

    /**
     * @param string $uri 
     * @param string $method 
     * @return object|bool 
     */
    public function match($uri, $method = Request::GET) {}


    public function __construct() {}


     function zephir_init_properties() {}

}
