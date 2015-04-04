<?php

namespace Owl\Http;

class Response
{

    const STATUS_CODE_OK = 200;


    protected $code = Response::STATUS_CODE_OK;


    protected $content;



	public function getCode() {}

    /**
     * @param mixed $code 
     */
	public function setCode($code) {}

    /**
     * @param mixed $content 
     */
	public function setContent($content) {}

}
