<?php
/**
 * @author Ivanov Sergey <xufocoder@gmail.com>
 */

use Owl\Log\Logger;
use Owl\Log\Record;
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

    public function testWritterRecordsInterval()
    {
        $commits            = 0;
        $record             = new Record( 1, 2, 3 );
        $intervals          = 5;
        $recordsPerInterval = 5;
        $records            = ( $recordsPerInterval + 1 ) * $intervals;

        $writer = new DevNull();
        $writer->setRecordsInterval( $recordsPerInterval );

        for ($i = 0; $i < $records; $i ++) {
            if ($i % ( $recordsPerInterval + 1 ) == 0) {
                $this->assertTrue( count( $writer->getRecords() ) == 0 );
                $commits ++;
            }
            $writer->commit( [
                $record,
            ] );
        }

        $this->assertTrue( count( $writer->getRecords() ) == 0 );
        $this->assertTrue( $intervals == $commits );
    }

    public function testSetFormatter()
    {
        $formatter = new \Owl\Log\Formatter\Json();

        $writer = new DevNull();
        $writer->setFormatter($formatter);

        $this->assertTrue( $writer->getFormatter() === $formatter );
    }

    public function testSetWrongFormatter()
    {
        $this->setExpectedException("Owl\\Log\\Exception\\InvalidFormatterException", "Formatter set error");

        $writer = new DevNull();
        $writer->setFormatter(1);
    }

    public function testSetExistsFormatter()
    {
        $writer = new DevNull();
        $writer->setFormatter("\\Owl\\Log\\Formatter\\Json");

        $formatter = $writer->getFormatter();

        $this->assertTrue( get_class($formatter) == "Owl\\Log\\Formatter\\Json" );
    }

    public function testSetNonExistsFormatter()
    {
        $this->setExpectedException("Owl\\Log\\Exception\\InvalidFormatterException", "Formatter class is not exits");

        $writer = new DevNull();
        $writer->setFormatter("NonExistsFormatter");
    }
}