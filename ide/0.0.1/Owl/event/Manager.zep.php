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


	public function __construct() {}

}
