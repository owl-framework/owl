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
     * @return mixed 
     */
	public function getService($name) {}


	public function __construct() {}

}
