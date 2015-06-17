<?php

namespace Owl\Log;


class Record
{
    /**
     * Record level
     */
    protected $level;

    /**
     * Record timestamp
     */
    protected $timestamp;

    /**
     * Record message
     */
    protected $message;


    /**
     * Interpolates context values into the message placeholders.
     *
     * @see http://www.php-fig.org/psr/psr-3/
     * @param string $message 
     * @param array $context 
     */
    protected function interpolate($message, $context = array()) {}

    /**
     * Create and interpolate record message
     *
     * @param mixed $level 
     * @param double $timestamp 
     * @param string $message 
     * @param array $context 
     */
    public function __construct($level, $timestamp, $message, $context = array()) {}

}
