<?php

namespace Owl\Router;

class Router
{

    protected $base;

    /**
     * @param mixed $request 
     */
	public function matchRequest(Owl\Http\Request $request) {}

    /**
     * @param string $uri 
     * @param string $method 
     * @return object|bool 
     */
	public function match($uri, $method = "GET") {}

}
