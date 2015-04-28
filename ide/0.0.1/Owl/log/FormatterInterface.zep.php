<?php

namespace Owl\Log;

interface FormatterInterface
{

    /**
     * Format record
     *
     * @param mixed $level 
     * @param double $timestamp 
     * @param string $message 
     * @param array $context 
     * @return string 
     */
    public function format($level, $timestamp, $message, $context = array());

}
