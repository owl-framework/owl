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
     * @var \Owl\Http\HeadersBag
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


    public function __toString() {}

    /**
     * @return \Owl\Http\HeadersBag 
     */
    public function getHeaders() {}


    public function __construct() {}

    /**
     * @return bool 
     */
    public function send() {}

    /**
     * Check whether status is OK
     *
     * @return bool 
     */
    public function isOk() {}

    /**
     * Check whether status is Server Error
     *
     * @return bool 
     */
    public function isServerError() {}

}
