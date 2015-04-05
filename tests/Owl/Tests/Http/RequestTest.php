<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

use Owl\Http\Request;

class RequestTest extends \PHPUnit_Framework_TestCase
{
    public function testRequest()
    {
        unset($_SERVER['REQUEST_URI']);
        $request = Request::createFromGlobals();

        $this->assertEquals('/', $request->getUri()); // By default it's /
        $this->assertEquals(Request::GET, $request->getMethod());

        $_SERVER['REQUEST_URI'] = '/';
        $request = Request::createFromGlobals();

        $this->assertEquals('/', $request->getUri());
        $this->assertEquals(Request::GET, $request->getMethod());

        $_SERVER['REQUEST_URI'] = '/test';
        $request = Request::createFromGlobals();

        $this->assertEquals('/test', $request->getUri());
        $this->assertEquals(Request::GET, $request->getMethod());
    }
} 