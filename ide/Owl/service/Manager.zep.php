<?php

namespace Owl\Service;


class Manager
{

    protected $instances = array();


    protected $services = array();


    /**
     * @param string $name 
     * @param mixed $definition 
     */
    public function set($name, $definition) {}

    /**
     * @param string $name 
     * @param mixed $definition 
     */
    public function setService($name, $definition) {}

    /**
     * @param string $name 
     */
    public function get($name) {}

    /**
     * @param string $name 
     * @return bool 
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


     function zephir_init_properties_Owl_Service_Manager() {}

}
