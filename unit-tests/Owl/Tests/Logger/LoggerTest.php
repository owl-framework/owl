<?php
/**
 * @author Ivanov Sergey <xufocoder@gmail.com>
 */

use Owl\Log\Logger;

/**
 * Class LoggerTest
 */
class LoggerTest extends \PHPUnit_Framework_TestCase {


    /**
     * @return array
     */
    protected function getLevels() {
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

    public function testLoggerRecordLevels() {

        $logger = new Logger( [ ] );

        $logger->alert( 'message' );
        $logger->critical( 'message' );
        $logger->debug( 'message' );
        $logger->emergency( 'message' );
        $logger->info( 'message' );
        $logger->notice( 'message' );
        $logger->warning( 'message' );

        $records = $logger->getRecords();

        $this->assertTrue( Logger::getLevelTitle( $records[0][0] ) == 'alert' );
        $this->assertTrue( Logger::getLevelTitle( $records[1][0] ) == 'critical' );
        $this->assertTrue( Logger::getLevelTitle( $records[2][0] ) == 'debug' );
        $this->assertTrue( Logger::getLevelTitle( $records[3][0] ) == 'emergency' );
        $this->assertTrue( Logger::getLevelTitle( $records[4][0] ) == 'info' );
        $this->assertTrue( Logger::getLevelTitle( $records[5][0] ) == 'notice' );
        $this->assertTrue( Logger::getLevelTitle( $records[6][0] ) == 'warning' );

    }

}