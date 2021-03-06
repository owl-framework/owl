<?php

namespace Owl\Event;


class Manager
{

    protected $listeners = array();


    /**
     * @param mixed $eventName 
     * @param callable $callback 
     */
    public function listen($eventName, $callback) {}

    /**
     * @param string $eventName 
     * @param mixed $data 
     */
    public function emit($eventName, $data = null) {}

}
