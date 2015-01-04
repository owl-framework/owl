<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

class RequestTest extends \PHPUnit_Framework_TestCase
{
    public function testRequest()
    {
        $_SERVER['REQUEST_URI'] = '/';

        $request = \Owl\Http\Request::createFromGlobals();
        $this->assertEquals('/', $request->getUri());
    }
} 