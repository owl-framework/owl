<?php

namespace Owl\Http;


interface RequestInterface
{

    /**
     * @return string|null 
     */
    public function getUri();

    /**
     * Get request path (URI without GET parameters)
     *
     * @return string 
     */
    public function getPath();

    /**
     * @param string $key 
     * @param mixed $defaultValue 
     */
    public function getParam($key, $defaultValue = null);

    /**
     * @param string $key 
     * @param mixed $defaultValue 
     */
    public function getPost($key, $defaultValue = null);

    /**
     * @param string $key 
     * @param mixed $defaultValue 
     */
    public function getServer($key, $defaultValue = null);

    /**
     * @return string 
     */
    public function getScheme();

}
