<?php
/**
 * @author Ivanov Sergey <xufocoder@gmail.com>
 */

namespace Owl\Tests\Log;

use Owl\Log\Logger;

/**
 * Class LoggerTest
 */
class LoggerTest extends \PHPUnit_Framework_TestCase
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

    public function testLoggerRecordLevels()
    {
        $logger = new Logger([

        ]);

        $logger->alert('message');
        $logger->critical('message');
        $logger->debug('message');
        $logger->emergency('message');
        $logger->info('message');
        $logger->notice('message');
        $logger->warning('message');

        $records = $logger->getRecords();

        $this->assertTrue(Logger::getLevelTitle($records[0]->level) == 'alert');
        $this->assertTrue(Logger::getLevelTitle($records[1]->level) == 'critical');
        $this->assertTrue(Logger::getLevelTitle($records[2]->level) == 'debug');
        $this->assertTrue(Logger::getLevelTitle($records[3]->level) == 'emergency');
        $this->assertTrue(Logger::getLevelTitle($records[4]->level) == 'info');
        $this->assertTrue(Logger::getLevelTitle($records[5]->level) == 'notice');
        $this->assertTrue(Logger::getLevelTitle($records[6]->level) == 'warning');
    }

    public function testLoggerFilterAllLevels()
    {
        $logger = new Logger([
            [
                'class' => '\Owl\Log\Writer\DevNull'
            ]
        ]);

        $logger->alert('test');
        for ($i = 0; $i < 5; $i ++) {
            $logger->error('test');
        }
        $logger->warning('test');

        $this->assertCount(7, $logger->getRecords());

        $logger->commit();
        $writer = $logger->getWriter(0);

        $this->assertCount(7, $writer->getRecords());
    }

    public function testLoggerFilterSeveralLevels()
    {
        $this->markTestSkipped('@ufocoder fix it please');

        $logger = new Logger([
            [
                'class'  => '\Owl\Log\Writer\DevNull',
                'levels' => [ Logger::LEVEL_ALERT ]
            ]
        ]);

        $logger->alert('test');
        for ($i = 0; $i < 5; $i ++) {
            $logger->error('test');
        }

        $this->assertCount(6, $logger->getRecords());

        $logger->commit();

        $writer = $logger->getWriter(0);

        $this->assertCount(1, $writer->getRecords());
    }

    public function testLoggerRecordsInterval()
    {
        $this->markTestSkipped('@ufocoder fix it please');

        $intervals          = 5;
        $recordsPerInterval = 5;
        $records            = ( $recordsPerInterval + 1 ) * $intervals;

        $logger = new Logger([
            [
                'class' => '\Owl\Log\Writer\DevNull'
            ]
        ]);

        $logger->setRecordsInterval($recordsPerInterval);

        $commits = 0;
        for ($i = 0; $i < $records; $i ++) {
            if ($i % ( $recordsPerInterval + 1 ) == 0) {
                $this->assertCount(0, $logger->getRecords());
                $commits ++;
            }
            $logger->warning('test');
        }

        $this->assertCount(0, $logger->getRecords());
        $this->assertSame($intervals, $commits);
    }
}
