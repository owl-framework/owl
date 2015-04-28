<?php

namespace Owl\Log;

class AbstractFormatter implements \Owl\Log\FormatterInterface
{

    /**
     * Interpolates context values into the message placeholders.
     *
     * @see http://www.php-fig.org/psr/psr-3/
     * @param string $message 
     * @param array $context 
     */
    protected function interpolate($message, $context = array()) {}

    /**
     * @inheritdoc
     * @param mixed $level 
     * @param double $timestamp 
     * @param string $message 
     * @param array $context 
     * @return string 
     */
    public function format($level, $timestamp, $message, $context = array()) {}

}
