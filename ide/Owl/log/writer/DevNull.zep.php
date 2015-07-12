<?php

namespace Owl\Log\Writer;

/**
 * Special writer for testing
 */
class DevNull extends \Owl\Log\AbstractWriter
{

    /**
     * @inheritdoc
     * @param string $record 
     */
    public function write($record) {}


     function zephir_init_properties_Owl_Log_Writer_DevNull() {}

}
