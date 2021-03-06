<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests\Http;

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
        $this->assertEquals('/', $request->getPath());
        $this->assertEquals(Request::GET, $request->getMethod());

        /**
         *
         */
        $_SERVER['REQUEST_URI'] = '/?code=1&test=2';
        $request = Request::createFromGlobals();

        $this->assertEquals('/?code=1&test=2', $request->getUri());
        $this->assertEquals('/', $request->getPath());
        $this->assertEquals(Request::GET, $request->getMethod());

        /**
         *
         */
        $_SERVER['REQUEST_URI'] = '/test';
        $request = Request::createFromGlobals();

        $this->assertEquals('/test', $request->getUri());
        $this->assertEquals('/test', $request->getPath());
        $this->assertEquals(Request::GET, $request->getMethod());

        /**
         *
         */
        $_SERVER['REQUEST_URI'] = '/test?code=1';
        $request = Request::createFromGlobals();

        $this->assertEquals('/test?code=1', $request->getUri());
        $this->assertEquals('/test', $request->getPath());
        $this->assertEquals(Request::GET, $request->getMethod());
    }

    public function testOwnRequest()
    {
        $request = new Request(
            [],
            [],
            [],
            [],
            [],
            []
        );

        $this->assertEquals('/', $request->getUri()); // By default it's /
        $this->assertEquals('/', $request->getPath());
        $this->assertEquals(Request::GET, $request->getMethod());

        $request = new Request(
            [
                'param1' => 5
            ],
            [
                'post1' => 5,
                'post2' => "test string"
            ],
            [
                'REQUEST_URI' => '/testuri'
            ],
            [],
            [],
            []
        );

        $this->assertEquals('/testuri', $request->getUri());
        $this->assertEquals('/testuri', $request->getPath());
        $this->assertEquals(Request::GET, $request->getMethod());

        $this->assertSame(5, $request->getParam('param1'));
        $this->assertSame(5, $request->getPost('post1'));
        $this->assertSame("test string", $request->getPost('post2'));
    }
}
