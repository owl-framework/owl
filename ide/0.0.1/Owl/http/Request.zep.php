<?php

namespace Owl\Http;

class Request
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

    protected $method;

    protected $get;

    protected $post;

    protected $server;

    protected $headers;

    protected $files;

    protected $cookies;


	public function getMethod() {}


	public function getParam() {}

    /**
     * @param string $key 
     */
	public function getPost($key) {}

    /**
     * @param string $key 
     */
	public function getServer($key) {}


	public function getScheme() {}

}
