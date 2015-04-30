<?php

namespace Owl\Log;

interface FormatterInterface
{

    /**
     * Format record
     *
     * @param mixed $record 
     * @return string 
     */
    public function format(Record $record);

}
