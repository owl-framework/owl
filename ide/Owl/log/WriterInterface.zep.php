<?php

namespace Owl\Log;

interface WriterInterface
{

    /**
     * Set formatter for writer
     *
     * @param mixed $formatter 
     */
    public function setFormatter($formatter);

    /**
     * Get formatter
     *
     * @return FormatterInterface 
     */
    public function getFormatter();

    /**
     * Set options for writer
     *
     * @param mixed $options 
     */
    public function setOptions($options);

    /**
     * Get options for writer
     *
     * @return array 
     */
    public function getOptions();

    /**
     * Get option for writer
     *
     * @param string $option 
     */
    public function getOption($option);

    /**
     * Set message levels for writer
     *
     * @param mixed $levels 
     */
    public function setLevels($levels);

    /**
     * Get message levels for writer
     *
     * @return array 
     */
    public function getLevels();

    /**
     * Commit pack of messages
     *
     * @param array $records 
     * @return bool 
     */
    public function commit($records);

    /**
     * Push all messages
     *
     * @return bool 
     */
    public function push();

}
