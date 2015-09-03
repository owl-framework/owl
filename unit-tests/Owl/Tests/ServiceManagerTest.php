<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests;

class ServiceManagerTest extends \PHPUnit_Framework_TestCase
{
    public function testSuccessConstructPass()
    {
        $serviceManager = new \Owl\Di\Container();
        $this->assertFalse($serviceManager->has('test'));

        $serviceManager->set('test', new \Owl\Router\Router());
        $this->assertTrue($serviceManager->has('test'));

        $this->assertInstanceOf('Owl\Router\Router', $serviceManager->get('test'));
    }

    /**
     * @expectedException Exception
     * @expectedExceptionMessage Instance wasn't found by name: test
     */
    public function testExceptionOnUnknownInstance()
    {
        $serviceManager = new \Owl\Di\Container();
        $this->assertFalse($serviceManager->has('test'));

        $serviceManager->get('test');
    }
}
