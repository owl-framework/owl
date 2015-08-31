<?php

namespace Owl\Mvc;


class View implements \Owl\Mvc\ViewInterface
{
    /**
     * Base path for views
     */
    protected $path = "./../resources/views/";


    /**
     * Base path for views
     */
    public function getPath() {}

    /**
     * Base path for views
     *
     * @param mixed $path 
     */
    public function setPath($path) {}

    /**
     * Render view
     *
     * @param string $path 
     * @param array $parameters 
     * @return string|bool 
     */
    public function render($path, $parameters = null) {}

}
