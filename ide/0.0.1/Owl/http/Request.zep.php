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


    protected $get;


    protected $post;


    protected $server;


    protected $headers;


    protected $files;


    protected $cookies;



	public function getMethod() {}

    /**
     * @return string|null 
     */
	public function getUri() {}

    /**
     * @param string $key 
     * @return variable|bool 
     */
	public function getParam($key) {}

    /**
     * @param string $key 
     * @return variable|bool 
     */
	public function getPost($key) {}

    /**
     * @param string $key 
     * @return variable|bool 
     */
	public function getServer($key) {}

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
