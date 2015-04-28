<?php

namespace Owl\Log\Formatter;

class Line extends \Owl\Log\AbstractFormatter
{

    /**
     * @param mixed $type 
     * @param double $timestamp 
     * @param string $message 
     * @param array $context 
     * @return string 
     */
    public function format($type, $timestamp, $message, $context = array()) {}

}
