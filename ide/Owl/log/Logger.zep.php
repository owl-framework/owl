<?php

namespace Owl\Log;

class Logger extends \Owl\Log\AbstractLogger implements \Owl\Log\LoggerInterface
{
    /**
     * Log records
     */
    protected $records = array();

    /**
     * Records limit to commit them to writers
     */
    protected $recordsInterval = 1000;

    /**
     * Log writers
     */
    protected $writers = array();


    /**
     * Log records
     */
    public function getRecords() {}

    /**
     * Records limit to commit them to writers
     */
    public function getRecordsInterval() {}

    /**
     * Log writers
     */
    public function getWriters() {}

    /**
     * @param mixed $writers 
     */
    public function __construct($writers = null) {}


    public function __destruct() {}

    /**
     * Create writer
     *
     * @param array $writerDescription 
     * @return \Owl\Log\WriterInterface 
     */
    protected function factoryWriter($writerDescription = array()) {}

    /**
     * Get writer
     *
     * @param string $name 
     * @return bool|\Owl\Log\WriterInterface 
     */
    public function getWriter($name) {}

    /**
     * @inheritdoc
     * @param mixed $level 
     * @param string $message 
     * @param array $context 
     */
    public function log($level, $message, $context = array()) {}

}
