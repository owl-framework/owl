<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

use Owl\Http\Request;
use Owl\Mvc\Controller;

class ControllerTest extends \PHPUnit_Framework_TestCase
{
    public function testSuccessConstructPass()
    {
        $controller = new Controller(Request::createFromGlobals(), new \Owl\Http\Response\Json(), new \Owl\Service\Manager());
        $this->assertInstanceOf('Owl\Http\RequestInterface', $controller->getRequest());
    }
} 