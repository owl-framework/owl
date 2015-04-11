<?php

namespace Owl\Http;

class Response implements \Owl\Http\ResponseInterface
{

    const STATUS_CODE_OK = 200;


    protected $code = Response::STATUS_CODE_OK;


    protected $content;


    protected $headers;



	public function getCode() {}

    /**
     * @param mixed $code 
     */
	public function setCode($code) {}


	public function getContent() {}

    /**
     * @param mixed $content 
     */
	public function setContent($content) {}


	public function getHeaders() {}


	public function __construct() {}

    /**
     * @return bool 
     */
	public function send() {}

}
