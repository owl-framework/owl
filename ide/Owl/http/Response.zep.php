<?php

namespace Owl\Http;


class Response implements \Owl\Http\ResponseInterface
{

    const STATUS_CODE_OK = 200;

    /**
     * @var int
     */
    protected $statusCode = Response::STATUS_CODE_OK;

    /**
     * @var string
     */
    protected $content = "";

    /**
     * @var \Owl\Http\HeadersBag
     */
    protected $headers;

    /**
     * @var boolean
     */
    protected $sent = false;


    /**
     * @return int 
     */
    public function getStatusCode() {}

    /**
     * @param int $statusCode 
     */
    public function setStatusCode($statusCode) {}

    /**
     * @return string 
     */
    public function getContent() {}

    /**
     * @param string $content 
     */
    public function setContent($content) {}

    /**
     * @return string 
     */
    public function __toString() {}

    /**
     * @return \Owl\Http\HeadersBag 
     */
    public function getHeaders() {}


    public function __construct() {}

    /**
     * Check if the response is already sent
     *
     * @return bool 
     */
    public function isSent() {}

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
