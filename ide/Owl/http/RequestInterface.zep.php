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
     * Get parameter from $_GET
     *
     * @param string $key 
     * @param mixed $defaultValue 
     */
    public function getParam($key, $defaultValue = null);

    /**
     * Get parameter from $_POST
     *
     * @param string $key 
     * @param mixed $defaultValue 
     */
    public function getPost($key, $defaultValue = null);

    /**
     * Get parameter from $_SERVER
     *
     * @param string $key 
     * @param mixed $defaultValue 
     */
    public function getServer($key, $defaultValue = null);

    /**
     * Get Request's scheme (HTTP/HTTPS)
     *
     * @return string 
     */
    public function getScheme();

    /**
     * Get Request's method (GET, POST, PUT, DELETE, OPTIONS, HEAD, TRACE, CONNECT, PATCH, PROPFIND)
     *
     * @return string 
     */
    public function getMethod();

}
