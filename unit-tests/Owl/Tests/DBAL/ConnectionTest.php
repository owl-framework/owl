<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests\DBAL;

use Owl\DBAL;
use Owl\Tests\Utils;

class ConnectionTest extends TestCase
{
    protected $connection;

    /**
     * Set connection
     */
    public function setUp()
    {
        $this->connection = Utils::getConnection();
    }

    public function testGetDriver()
    {
        $this->assertInstanceOf('Owl\DBAL\Driver\\' . $this->getDriverName(), $this->connection->getDriver());
    }

    public function testPrepare()
    {
        $sql = 'SELECT * FROM `users`';

        /**
         * We dont use own PDOStatement via it's not supported for PERSISTENT connections
         */
        $this->assertInstanceOf('PDOStatement', $this->connection->prepare($sql));
    }

    public function testIsConnection()
    {
        $this->assertTrue($this->connection instanceof DBAL\Connection);
    }
}
