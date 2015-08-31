<?php

namespace Owl\Mvc;


interface ViewInterface
{

    /**
     * @return string 
     */
    public function getPath();

    /**
     * Render view
     *
     * @param string $path 
     * @param array $parameters 
     * @return string|bool 
     */
    public function render($path, $parameters = null);

}
