<?php

namespace Owl\Http;

interface RequestInterface
{

    /**
     * @return string|null 
     */
    public function getUri();

    /**
     * @param string $key 
     * @param mixed $defaultValue 
     * @return string 
     */
    public function getPost($key, $defaultValue = null);

    /**
     * @param string $key 
     * @param mixed $defaultValue 
     * @return string 
     */
    public function getServer($key, $defaultValue = null);

    /**
     * @return string 
     */
    public function getScheme();

}
