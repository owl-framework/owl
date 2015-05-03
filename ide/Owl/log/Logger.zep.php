<?php

namespace Owl\Log;

class Logger extends \Owl\Log\AbstractLogger implements \Owl\Log\LoggerInterface
{
    /**
     * Array of <Record> elements
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
     * Array of <Record> elements
     */
    public function getRecords() {}

    /**
     * Records limit to commit them to writers
     */
    public function getRecordsInterval() {}

    /**
     * Records limit to commit them to writers
     *
     * @param mixed $recordsInterval 
     */
    public function setRecordsInterval($recordsInterval) {}

    /**
     * Log writers
     */
    public function getWriters() {}

    /**
     * @param array $writers 
     */
    public function __construct($writers = array()) {}


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
     * Commit records
     */
    public function commit() {}

    /**
     * @inheritdoc
     * @param mixed $level 
     * @param string $message 
     * @param array $context 
     */
    public function log($level, $message, $context = array()) {}

}
