<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests\Std;

use Owl\Std\ArrayBag;

class ArrayBagTest extends \PHPUnit_Framework_TestCase
{
    public function testSimple()
    {
        $bag = new ArrayBag(['test1' => true, 'test2' => false]);
        $this->assertCount(2, $bag);

        $this->assertTrue($bag->has('test1'));
        $this->assertEquals(true, $bag->get('test1'));
        $this->assertEquals(true, $bag->get('test1', false));

        $this->assertTrue($bag->has('test2'));
        $this->assertEquals(false, $bag->get('test2'));
        $this->assertEquals(false, $bag->get('test2', true));

        $this->assertFalse($bag->has('test3'));

        $this->assertEquals(null, $bag->get('test3'));
        $this->assertEquals(true, $bag->get('test3', true));
        $this->assertEquals(12345, $bag->get('test3', 12345));
    }

    public function testCount()
    {
        $bag = new ArrayBag([]);
        $this->assertCount(0, $bag);

        $bag = new ArrayBag(['test' => 1]);
        $this->assertCount(1, $bag);

        $bag->set('test1', true);
        $this->assertCount(2, $bag);
    }
}
