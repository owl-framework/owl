<?php

namespace Owl\Service;

class Manager
{

    protected $instances = array();


    protected $services = array();


    /**
     * @param string $name 
     * @param mixed $service 
     */
    public function setService($name, $service) {}

    /**
     * @param string $name 
     */
    public function get($name) {}

    /**
     * @param string $name 
     */
    public function has($name) {}

    /**
     * @param string $name 
     * @return variable 
     */
    public function getInstance($name) {}

    /**
     * @param string $name 
     * @return variable 
     */
    public function getService($name) {}


    public function __construct() {}

}
