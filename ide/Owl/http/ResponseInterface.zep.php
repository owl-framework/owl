<?php

namespace Owl\Http;


interface ResponseInterface
{

    /**
     * @return bool 
     */
    public function send();

    /**
     * @return string 
     */
    public function getContent();

    /**
     * @param int $code 
     */
    public function setCode($code);

    /**
     * @return int 
     */
    public function getCode();

}
