<?php
/**
 * @author: Patsura Dmitry @ovr <talk@dmtry.me>
 */

namespace Owl\Tests\Cache\Driver;

/**
 * Class TestCase
 */
class RedisTest extends TestCase
{
    public function setUp()
    {
        if (!extension_loaded($this->getDriverName())) {
            $this->markTestSkipped('The ' . __CLASS__ .' requires the use of ' . $this->getDriverName() . ' exstension');
        }
    }
    
    public function getDriverName()
    {
        return 'redis';
    }

    public function testConstruct()
    {
        $driver = $this->getDriver();
        $this->assertTrue(true);
    }

    public function testSetInstanceSuccess()
    {
        $driver = $this->getDriver();
        $client = new \Redis();
        $client->connect('localhost');
        $driver->setInstance($client);
    }

    public function testGetInstance()
    {
        $driver = $this->getDriver();
        $this->assertInstanceOf('Redis', $driver->getInstance());
    }
}
