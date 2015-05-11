<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests;

class ServiceManagerTest extends \PHPUnit_Framework_TestCase
{
    public function testSuccessConstructPass()
    {
        $serviceManager = new \Owl\Service\Manager();
        $this->assertFalse($serviceManager->has('test'));

        $serviceManager->setService('test', new \Owl\Router\Router());
        $this->assertTrue($serviceManager->has('test'));
    }
}
