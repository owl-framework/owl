<?php

namespace Owl\Router;

interface RouterInterface
{

    /**
     * @param mixed $request 
     */
	public function matchRequest(Owl\Http\RequestInterface $request);

    /**
     * @param string $uri 
     * @param string $method 
     * @return object|bool 
     */
	public function match($uri, $method = Request::GET);

}
