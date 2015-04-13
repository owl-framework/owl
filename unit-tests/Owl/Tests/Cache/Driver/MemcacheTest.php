<?php
/**
 * @author: Patsura Dmitry @ovr <talk@dmtry.me>
 */

/**
 * Class TestCase
 */
class MemcacheTest extends TestCase
{
    public function getDriverName()
    {
        return 'memcache';
    }
    public function testConstruct()
    {
        $driver = $this->getDriver();
        $this->assertTrue(true);
    }
    public function testSetInstanceSuccess()
    {
        $driver = $this->getDriver();
        $client = new \Memcache();
        $client->addserver('localhost');
        $driver->setInstance($client);
    }
}
