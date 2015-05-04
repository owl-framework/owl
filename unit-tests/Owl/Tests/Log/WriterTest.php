<?php
/**
 * @author Ivanov Sergey <xufocoder@gmail.com>
 */

namespace Owl\Tests\Log;

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
        $writer->setLevels($levels);

        $this->assertTrue($levels == $writer->getLevels());
    }

    public function testWritterRecordsInterval()
    {
        $record             = new Record(1, 2, 3);

        $commits            = 0;
        $intervals          = 5;
        $recordsPerInterval = 5;
        $records            = $recordsPerInterval * $intervals;

        $writer = new DevNull();
        $writer->setRecordsInterval($recordsPerInterval);

        for ($i = 1; $i <= $records; $i ++) {
            $writer->commit([
                $record,
            ]);

            if ($i % $recordsPerInterval == 0) {
                $this->assertCount(0, $writer->getRecords());
                $commits ++;
            }
        }

        $this->assertCount(0, $writer->getRecords());
        $this->assertSame($intervals, $commits);
    }

    public function testSetFormatter()
    {
        $formatter = new \Owl\Log\Formatter\Json();

        $writer = new DevNull();
        $writer->setFormatter($formatter);

        $this->assertTrue($writer->getFormatter() === $formatter);
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

        $this->assertTrue(get_class($formatter) == "Owl\\Log\\Formatter\\Json");
    }

    public function testSetNonExistsFormatter()
    {
        $this->setExpectedException("Owl\\Log\\Exception\\InvalidFormatterException", "Formatter class is not exits");

        $writer = new DevNull();
        $writer->setFormatter("NonExistsFormatter");
    }
}
