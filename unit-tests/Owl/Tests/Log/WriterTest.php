<?php
/**
 * @author Ivanov Sergey <xufocoder@gmail.com>
 */

use Owl\Log\Logger;
use Owl\Log\Writer\DevNull;

/**
 * Class WriterTest
 */
class WriterTest extends \PHPUnit_Framework_TestCase
{
    /**
     * @return array
     */
    protected function getLevels()
    {
        return [
            Logger::LEVEL_ALERT,
            Logger::LEVEL_CRITICAL,
            Logger::LEVEL_DEBUG,
            Logger::LEVEL_EMERGENCY,
            Logger::LEVEL_INFO,
            Logger::LEVEL_NOTICE,
            Logger::LEVEL_WARNING
        ];
    }

    public function testWriterLevels()
    {
        $levels = $this->getLevels();

        $writer = new DevNull();
        $writer->setLevels( $levels );

        $this->assertTrue( $levels == $writer->getLevels() );
    }

}