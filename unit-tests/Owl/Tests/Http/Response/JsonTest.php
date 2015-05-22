<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests\Http\Response;

use Owl\Http\Response\Json;

class JsonTest extends \Owl\Tests\Http\ResponseTest
{
    public function testGetSetContent()
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
