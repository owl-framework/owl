<?php

namespace Owl\Router\Http;

class DynamicRoute extends \Owl\Router\Route
{

    protected $pattern;


    protected $uriParameters;


    /**
     * @param string $uri 
     */
    public function __construct($uri) {}


    public function getPattern() {}

    /**
     * @param string $uri 
     * @return bool|array 
     */
    public function match($uri) {}

}
