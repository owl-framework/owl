<?php

namespace Owl\Http;

class Response implements \Owl\Http\ResponseInterface
{

    const STATUS_CODE_OK = 200;


    protected $code = Response::STATUS_CODE_OK;


    protected $content;



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

    /**
     * @return bool 
     */
	public function send() {}

}
