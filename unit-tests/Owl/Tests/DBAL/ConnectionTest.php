<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests\DBAL;

use Owl\DBAL;
use Owl\Tests\Utils;

class ConnectionTest extends TestCase
{
    protected $_connection;

    /**
     * Set connection
     */
    public function setUp()
    {
        $this->_connection = Utils::getConnection();
    }

    public function testGetDriver()
    {
        $this->assertInstanceOf('Owl\DBAL\Driver\\' . $this->getDriverName(), $this->_connection->getDriver());
    }

    public function testPrepare()
    {
        $sql = 'SELECT * FROM `users`';
        $this->assertInstanceOf('Owl\DBAL\Driver\PDO\Statement', $this->_connection->prepare($sql));
    }

    public function testIsConnection()
    {
        $this->assertTrue($this->_connection instanceof DBAL\Connection);
    }
}
