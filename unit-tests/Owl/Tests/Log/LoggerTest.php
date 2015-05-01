<?php
/**
 * @author Ivanov Sergey <xufocoder@gmail.com>
 */

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

        $logger = new Logger( [ ] );

        $logger->alert( 'message' );
        $logger->critical( 'message' );
        $logger->debug( 'message' );
        $logger->emergency( 'message' );
        $logger->info( 'message' );
        $logger->notice( 'message' );
        $logger->warning( 'message' );

        $records = $logger->getRecords();

        $this->assertTrue( Logger::getLevelTitle( $records[0]->level ) == 'alert' );
        $this->assertTrue( Logger::getLevelTitle( $records[1]->level ) == 'critical' );
        $this->assertTrue( Logger::getLevelTitle( $records[2]->level ) == 'debug' );
        $this->assertTrue( Logger::getLevelTitle( $records[3]->level ) == 'emergency' );
        $this->assertTrue( Logger::getLevelTitle( $records[4]->level ) == 'info' );
        $this->assertTrue( Logger::getLevelTitle( $records[5]->level ) == 'notice' );
        $this->assertTrue( Logger::getLevelTitle( $records[6]->level ) == 'warning' );

    }

    public function testLoggerFilterAllLevels()
    {

        $logger = new Logger( [
            [
                'class' => '\Owl\Log\Writer\DevNull'
            ]
        ] );

        $logger->alert( 'test' );
        for ($i = 0; $i < 5; $i ++) {
            $logger->error( 'test' );
        }
        $logger->warning( 'test' );

        $this->assertTrue( count( $logger->getRecords() ) == 7 );

        $logger->commit();
        $writer = $logger->getWriter( 0 );

        $this->assertTrue( count( $writer->getRecords() ) == 7 );
    }

    public function testLoggerFilterSeveralLevels()
    {

        $logger = new Logger( [
            [
                'class'  => '\Owl\Log\Writer\DevNull',
                'levels' => [ Logger::LEVEL_ALERT ]
            ]
        ] );

        $logger->alert( 'test' );
        for ($i = 0; $i < 5; $i ++) {
            $logger->error( 'test' );
        }

        $this->assertTrue( count( $logger->getRecords() ) == 6 );

        $logger->commit();

        $writer = $logger->getWriter( 0 );

        $this->assertTrue( count( $writer->getRecords() ) == 1 );
    }

    public function testLoggerRecordsInterval()
    {
        $intervals          = 5;
        $recordsPerInterval = 5;
        $records            = ( $recordsPerInterval + 1 ) * $intervals;

        $logger = new Logger( [
            [
                'class' => '\Owl\Log\Writer\DevNull'
            ]
        ] );

        $logger->setRecordsInterval( $recordsPerInterval );

        $commits = 0;
        for ($i = 0; $i < $records; $i ++) {
            if ($i % ( $recordsPerInterval + 1 ) == 0) {
                $this->assertTrue( count( $logger->getRecords() ) == 0 );
                $commits ++;
            }
            $logger->warning( 'test' );
        }

        $this->assertTrue( count( $logger->getRecords() ) == 0 );
        $this->assertTrue( $intervals == $commits );
    }

}