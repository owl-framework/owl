<?php

namespace Owl\Log;


abstract class AbstractLogger implements \Owl\Log\LoggerInterface
{
    /**
     * Log levers constants
     */
    const LEVEL_ALERT = 0x01;


    const LEVEL_CRITICAL = 0x02;


    const LEVEL_EMERGENCY = 0x03;


    const LEVEL_ERROR = 0x04;


    const LEVEL_INFO = 0x05;


    const LEVEL_DEBUG = 0x06;


    const LEVEL_NOTICE = 0x07;


    const LEVEL_WARNING = 0x08;


    /**
     * Get level title by internal level code
     *
     * @param mixed $level 
     * @return string 
     */
    public static function getLevelTitle($level) {}

    /**
     * @inheritdoc
     * @param string $message 
     * @param array $context 
     */
    public function emergency($message, $context = array()) {}

    /**
     * @inheritdoc
     * @param string $message 
     * @param array $context 
     */
    public function alert($message, $context = array()) {}

    /**
     * @inheritdoc
     * @param string $message 
     * @param array $context 
     */
    public function critical($message, $context = array()) {}

    /**
     * @inheritdoc
     * @param string $message 
     * @param array $context 
     */
    public function error($message, $context = array()) {}

    /**
     * @inheritdoc
     * @param string $message 
     * @param array $context 
     */
    public function warning($message, $context = array()) {}

    /**
     * @inheritdoc
     * @param string $message 
     * @param array $context 
     */
    public function notice($message, $context = array()) {}

    /**
     * @inheritdoc
     * @param string $message 
     * @param array $context 
     */
    public function info($message, $context = array()) {}

    /**
     * @inheritdoc
     * @param string $message 
     * @param array $context 
     */
    public function debug($message, $context = array()) {}

    /**
     * @inheritdoc
     * @param mixed $level 
     * @param string $message 
     * @param array $context 
     */
    abstract public function log($level, $message, $context = array());

}
