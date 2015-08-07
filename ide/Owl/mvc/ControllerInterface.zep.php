<?php

namespace Owl\Mvc;


interface ControllerInterface
{

    /**
     * @param mixed $request 
     * @param mixed $response 
     * @param mixed $di 
     */
    public function __construct(\Owl\Http\Request $request, \Owl\Http\Response $response, \Owl\Di\ContainerInterface $di);

}
