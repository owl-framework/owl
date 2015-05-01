<?php
/**
 * @author Ivanov Sergey <xufocoder@gmail.com>
 */

use Owl\Log\Writer\DevNull;

/**
 * Class WriterTest
 */
class WriterTest extends \PHPUnit_Framework_TestCase
{
    public function testTransportLevels()
    {
        $levels = $this->getLevels();

        $writer = new DevNull();
        $writer->setLevels( $levels );

        $this->assertTrue( $levels == $writer->getLevels() );
    }

}