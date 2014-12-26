<?php

namespace Owl\Router;

interface RouterInterface
{

    /**
     * @param string $uri 
     * @param string $method 
     * @return object|bool 
     */
	public function match($uri, $method = "GET");

}
