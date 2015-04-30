<?php

namespace Owl\Mvc;

class View
{

    protected $path = "./../resources/views/";



    public function getPath() {}

    /**
     * @param mixed $path 
     */
    public function setPath($path) {}

    /**
     * @param string $path 
     * @param array $parameters 
     */
    public function render($path, $parameters = null) {}

}
