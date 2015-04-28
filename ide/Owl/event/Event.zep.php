<?php

namespace Owl\Event;

class Event
{

    protected $name;


    protected $data;



    public function getName() {}


    public function getData() {}

    /**
     * @param mixed $name 
     * @param mixed $data 
     */
    public function __construct($name, $data) {}

}
