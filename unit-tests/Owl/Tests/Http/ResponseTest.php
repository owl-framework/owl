<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests\Http;

use Owl\Http\Response;

class ResponseTest extends \PHPUnit_Framework_TestCase
{
    public function testGetSetCode()
    {
        $response = new Response();
        $this->assertSame(200, $response->getStatusCode());

        $response->setStatusCode(404);
        $this->assertSame(404, $response->getStatusCode());

        $response->setStatusCode(500);
        $this->assertSame(500, $response->getStatusCode());
    }

    public function testGetSetContent()
    {
        $response = new Response();
        $this->assertSame("", $response->getContent());

        $response->setContent("test");
        $this->assertSame("test", $response->getContent());

        $response->setContent("Hello World!");
        $this->assertSame("Hello World!", $response->getContent());
    }
}
