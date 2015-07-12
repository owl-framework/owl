<?php

namespace Owl\Log;


abstract class AbstractWriter implements \Owl\Log\WriterInterface
{
    /**
     * Writer log levels
     */
    protected $levels = array();

    /**
     * Writer records
     */
    protected $records = array();

    /**
     * Writer options
     */
    protected $options = array();

    /**
     * Writer formatter
     */
    protected $formatter;

    /**
     * Records limit to commit them to writers
     */
    protected $recordsInterval = 1000;


    /**
     * Writer log levels
     */
    public function getLevels() {}

    /**
     * Writer log levels
     *
     * @param mixed $levels 
     */
    public function setLevels($levels) {}

    /**
     * Writer records
     */
    public function getRecords() {}

    /**
     * Writer options
     */
    public function getOptions() {}

    /**
     * Writer options
     *
     * @param mixed $options 
     */
    public function setOptions($options) {}

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


    public function __destruct() {}

    /**
     * @inheritdoc
     * @param string $option 
     * @param mixed $value 
     */
    public function setOption($option, $value) {}

    /**
     * @inheritdoc
     * @param string $option 
     */
    public function getOption($option) {}

    /**
     * @return \Owl\Log\FormatterInterface 
     */
    protected function defaultFormatter() {}

    /**
     * @inheritdoc
     * @return \Owl\Log\FormatterInterface 
     */
    public function getFormatter() {}

    /**
     * @param mixed $formatter 
     */
    public function setFormatter($formatter) {}

    /**
     * @param mixed $record 
     * @return string 
     */
    protected function format(Record $record) {}

    /**
     * Filter records by levels
     *
     * @param array $records 
     * @return array 
     */
    protected function filterRecords($records) {}

    /**
     * @inheritdoc
     * @param array $records 
     */
    public function commit($records) {}

    /**
     * @inheritdoc
     */
    public function push() {}

    /**
     * Write record
     *
     * @param string $record 
     */
    abstract protected function write($record);


     function zephir_init_properties_Owl_Log_AbstractWriter() {}

}
