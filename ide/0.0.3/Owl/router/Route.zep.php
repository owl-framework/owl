<?php

namespace Owl\Router;

abstract class Route
{

    const GET = 1;


    const POST = 2;


    const DELETE = 3;


    const PUT = 4;


    const ALL = 7;


    protected $uri;


    protected $method = self::ALL;


    protected $parameters;


}
