<?php

namespace Owl\Log\Writer;

class DevNull extends \Owl\Log\AbstractWriter
{

    /**
     * @inheritdoc
     * @param string $record 
     */
    public function write($record) {}

}
