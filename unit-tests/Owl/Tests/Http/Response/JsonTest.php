<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests\Http\Response;

use Owl\Http\Response\Json;

class JsonTest extends \PHPUnit_Framework_TestCase
{
    public function testSimple()
    {
        $response = new Json();
        $this->assertSame(200, $response->getCode());

        $response->setCode(404);
        $this->assertSame(404, $response->getCode());

        $response->setCode(500);
        $this->assertSame(500, $response->getCode());
    }

    public function testContentJson()
    {
        $response = new Json();
        $response->setContent(true);
        $this->assertEquals('true', $response->getContent());

        $response = new Json();
        $response->setContent('foo');
        $this->assertEquals('"foo"', $response->getContent());

        $response = new Json();
        $response->setContent(array('foo' => 'bar'));
        $this->assertEquals('{"foo":"bar"}', $response->getContent());
    }
}
