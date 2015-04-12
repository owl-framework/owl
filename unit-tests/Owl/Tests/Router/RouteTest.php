<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

class RouteTest extends \PHPUnit_Framework_TestCase
{
    public function testParameterParsing()
    {
        $router = new \Owl\Router\Http\DynamicRoute('/user/id:int/');
        $result = $router->match('/user/1/');

        $this->assertInternalType('array', $result);
        $this->assertCount(1, $result);
    }
}
