<?php
/**
 * @author: Patsura Dmitry @ovr <talk@dmtry.me>
 */

/**
 * Class TestCase
 */
class MemcachedTest extends TestCase
{
    public function getDriverName()
    {
        return 'memcached';
    }

    public function testConstruct()
    {
        $driver = $this->getDriver();
        $this->assertTrue(true);
    }

    public function testSetInstanceSuccess()
    {
        $driver = $this->getDriver();
        $driver->setInstance(new \Memcached());
    }

    public function testGetInstance()
    {
        $driver = $this->getDriver();
        $this->assertInstanceOf('Memcached', $driver->getInstance());
    }
}
