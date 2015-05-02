<?php

namespace Owl\Tests;

use Owl\Event\Manager;

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

class EventManagerTest extends \PHPUnit_Framework_TestCase
{
    public function testSimple()
    {
        $runs = 0;

        $em = new Manager();
        $em->listen('test', function () use (&$runs) {
            $runs++;
        });

        $em->emit('test');
        $em->emit('test');
        $em->emit('test');

        $this->assertSame(3, $runs);
    }

    protected $runs = 0;

    public function simpleListen()
    {
        $this->runs++;
    }

    public function testSimpleCallableThis()
    {
        $this->assertSame(0, $this->runs);

        $em = new Manager();
        $em->listen('test', [$this, 'simpleListen']);

        $em->emit('test');
        $em->emit('test');
        $em->emit('test');

        $this->assertSame(3, $this->runs);
    }
}
