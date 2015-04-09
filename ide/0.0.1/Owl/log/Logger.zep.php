<?php

namespace Owl\Log;

class Logger implements \Owl\Log\LoggerInterface
{

    const EMERGENCY = "emergency";


    const ALERT = "alert";


    const CRITICAL = "critical";


    const ERROR = "error";


    const WARNING = "warning";


    const NOTICE = "notice";


    const INFO = "info";


    const DEBUG = "debug";


    /**
     * System is unusable.
     *
     * @param string $message 
     * @param array $context 
     */
	public function emergency($message, $context = array()) {}

    /**
     * Action must be taken immediately.
     * Example: Entire website down, database unavailable, etc. This should
     * trigger the SMS alerts and wake you up.
     *
     * @param string $message 
     * @param array $context 
     */
	public function alert($message, $context = array()) {}

    /**
     * Critical conditions.
     * Example: Application component unavailable, unexpected exception.
     *
     * @param string $message 
     * @param array $context 
     */
	public function critical($message, $context = array()) {}

    /**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     *
     * @param string $message 
     * @param array $context 
     */
	public function error($message, $context = array()) {}

    /**
     * Exceptional occurrences that are not errors.
     * Example: Use of deprecated APIs, poor use of an API, undesirable things
     * that are not necessarily wrong.
     *
     * @param string $message 
     * @param array $context 
     */
	public function warning($message, $context = array()) {}

    /**
     * Normal but significant events.
     *
     * @param string $message 
     * @param array $context 
     */
	public function notice($message, $context = array()) {}

    /**
     * Interesting events.
     * Example: User logs in, SQL logs.
     *
     * @param string $message 
     * @param array $context 
     */
	public function info($message, $context = array()) {}

    /**
     * Detailed debug information.
     *
     * @param string $message 
     * @param array $context 
     */
	public function debug($message, $context = array()) {}

    /**
     * Logs with an arbitrary level.
     *
     * @param mixed $level 
     * @param string $message 
     * @param array $context 
     */
	public function log($level, $message, $context = array()) {}

}
