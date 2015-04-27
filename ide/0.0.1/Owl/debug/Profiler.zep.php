<?php

namespace Owl\Debug;

class Profiler
{

    protected $startTime;



    public function __construct() {}

    /**
     * @param mixed $event 
     */
    public function logEvent($event) {}

    /**
     * @param mixed $em 
     */
    public function listen(\Owl\Event\Manager $em) {}

}
