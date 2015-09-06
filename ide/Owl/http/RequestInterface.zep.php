<?php

namespace Owl\Http;


interface RequestInterface
{

    /**
     * Get Request's URI
     *
     * @return string 
     */
    public function getUri();

    /**
     * Get Request's path (URI without GET parameters)
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

    /**
     * @return string 
     */
    public function getMethod();

}
