<?php

namespace Owl\Http;

class Response implements \Owl\Http\ResponseInterface
{

    const STATUS_CODE_OK = 200;

    /**
     * @var int
     */
    protected $code = Response::STATUS_CODE_OK;

    /**
     * @var string
     */
    protected $content = "";

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected $headers;


    /**
     * @return int 
     */
    public function getCode() {}

    /**
     * @param int $code 
     */
    public function setCode($code) {}

    /**
     * @return string 
     */
    public function getContent() {}

    /**
     * @param string $content 
     */
    public function setContent($content) {}

    /**
     * @return \Owl\Std\ArrayBag 
     */
    public function getHeaders() {}


    public function __construct() {}

    /**
     * @return bool 
     */
    public function send() {}

}
