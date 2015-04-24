<?php
/**
 * @author: Patsura Dmitry @ovr <talk@dmtry.me>
 */

/**
 * Class TestCase
 */
class RedisTest extends TestCase
{
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
