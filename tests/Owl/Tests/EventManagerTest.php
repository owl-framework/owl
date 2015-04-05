<?php
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
        $em->listen('test', function() use (&$runs) {
            $runs++;
        });

        $em->emit('test');
        $em->emit('test');
        $em->emit('test');

        $this->assertSame(3, $runs);
    }
} 