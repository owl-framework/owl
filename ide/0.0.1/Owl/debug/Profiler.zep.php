<?php

namespace Owl\Debug;

class Profiler
{

    protected $startTime;


    protected $lastTime;



    public function __construct() {}

    /**
     * @param mixed $event 
     */
    public function logEvent(\Owl\Event\Event $event) {}

    /**
     * @param mixed $em 
     */
    public function listen(\Owl\Event\Manager $em) {}


    public function show() {}

}
