<?php
/**
 * @author: Patsura Dmitry @ovr <talk@dmtry.me>
 */

namespace Owl\Tests\Cache\Driver;

use \Cacher\Driver\Memcache;

/**
 * Class TestCase
 */
abstract class TestCase extends \PHPUnit_Framework_TestCase
{
    /**
     * @return string
     */
    abstract public function getDriverName();

    /**
     * @return \Owl\Cache\Driver
     */
    public function getDriver()
    {
        $name = '\\Owl\\Cache\\Driver\\' . ucfirst($this->getDriverName());

        return new $name();
    }

    public function testInterfaceImplementation()
    {
        $driver = $this->getDriver();
        $this->assertInstanceOf('Owl\Cache\Driver', $driver);
    }

    public function testIntWorkFlow()
    {
        $this->workFlowTest('test_int1', 0);
        $this->workFlowTest('test_int2', 1);
        $this->workFlowTest('test_int3', 100);
        $this->workFlowTest('test_int4', -153223532);
    }

    public function testFloatWorkFlow()
    {
        $this->workFlowTest('test_float1', 1.0);
        $this->workFlowTest('test_float2', 3432.4352352342);
        $this->workFlowTest('test_float3', -1.42343);
    }

    public function testArrayWorkFlow()
    {
        $this->workFlowTest('test_array1', []);
        $this->workFlowTest('test_array2', [1, 2, 3]);
        $this->workFlowTest('test_array3', [1, [1, 2, 3], 2, 3]);
    }

    public function testStringWorkFlow()
    {
        $this->workFlowTest('test_string1', "");
        $this->workFlowTest('test_string2', "test string");
        $this->workFlowTest('test_string3', "test \\string \\test \w+fdsfsd");
    }

    /**
     * @param $id
     * @param $value
     */
    protected function workFlowTest($id, $value)
    {
        $driver = $this->getDriver();

        /**
         * Simple
         */
        $driver->save($id, $value);
        $this->assertTrue($driver->exists($id));
        $this->assertEquals($value, $driver->get($id));

        /**
         * Delete
         */
        $driver->delete($id);
        $this->assertFalse($driver->exists($id));

        /**
         * Flush
         */
        $driver->save($id, $value);
        $this->assertTrue($driver->exists($id));
        $driver->flush();
        $this->assertFalse($driver->exists($id));
    }

    abstract public function testSetInstanceSuccess();

    /**
     * @expectedException     PHPUnit_Framework_Error
     */
    public function testSetInstanceException()
    {
        $driver = $this->getDriver();
        $driver->setInstance(false);
    }
}
