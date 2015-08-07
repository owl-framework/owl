<?php

namespace Owl\Http;


class Request implements \Owl\Http\RequestInterface
{

    const GET = "GET";


    const POST = "POST";


    const PUT = "PUT";


    const DELETE = "DELETE";


    const OPTIONS = "OPTIONS";


    const HEAD = "HEAD";


    const TRACE = "TRACE";


    const CONNECT = "CONNECT";


    const PATCH = "PATCH";


    const PROPFIND = "PROPFIND";


    protected $method = self::GET;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected $get;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected $post;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected $server;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected $headers;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected $files;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected $cookies;



    public function getMethod() {}

    /**
     * Get request URI
     *
     * @return string 
     */
    public function getUri() {}

    /**
     * Get request path (URI without GET parameters)
     *
     * @return string 
     */
    public function getPath() {}

    /**
     * @param string $key 
     * @param mixed $defaultValue 
     */
    public function getParam($key, $defaultValue = null) {}

    /**
     * @param string $key 
     * @param mixed $defaultValue 
     * @return mixed|bool 
     */
    public function getPost($key, $defaultValue = null) {}

    /**
     * @param string $key 
     * @param mixed $defaultValue 
     * @return mixed|bool 
     */
    public function getServer($key, $defaultValue = null) {}

    /**
     * @return string 
     */
    public function getScheme() {}

    /**
     * @param mixed $get 
     * @param mixed $post 
     * @param mixed $server 
     * @param mixed $headers 
     * @param mixed $files 
     * @param mixed $cookies 
     */
    public function __construct($get, $post, $server, $headers, $files, $cookies) {}

    /**
     * @return Request 
     */
    public static function createFromGlobals() {}

}
