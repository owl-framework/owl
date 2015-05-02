<?php
/**
 * @author: Patsura Dmitry @ovr <talk@dmtry.me>
 */

namespace Owl\Tests\Cache\Driver;

/**
 * Class TestCase
 */
class NativeArrayTest extends TestCase
{
    public function getDriverName()
    {
        return 'NativeArray';
    }

    public function testConstruct()
    {
        $driver = $this->getDriver();
        $this->assertTrue(true);
    }

    public function testSetInstanceSuccess()
    {
        $driver = $this->getDriver();
        $driver->setInstance(array());
    }

    public function testGetInstance()
    {
        $driver = $this->getDriver();
        $this->assertInternalType('array', $driver->getInstance());
    }
}
