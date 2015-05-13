<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests\Http;

use Owl\Http\Response;

class ResponseTest extends \PHPUnit_Framework_TestCase
{
    public function testSimple()
    {
        $response = new Response();
        $this->assertSame(200, $response->getCode());

        $response->setCode(404);
        $this->assertSame(404, $response->getCode());

        $response->setCode(500);
        $this->assertSame(500, $response->getCode());
    }
}
