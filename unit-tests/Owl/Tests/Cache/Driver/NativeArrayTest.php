<?php
/**
 * @author: Patsura Dmitry @ovr <talk@dmtry.me>
 */

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
}