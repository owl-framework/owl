<?php

namespace Owl\Di;


class Container implements \Owl\Di\ContainerInterface
{
    /**
     * Service definitions
     *
     * @var array
     */
    protected $services = array();

    /**
     * Service object instances
     *
     * @var array
     */
    protected $instances = array();


    /**
     * @param string $name 
     * @param mixed $definition 
     */
    public function setService($name, $definition) {}

    /**
     * @param string $name 
     * @param mixed $definition 
     */
    public function set($name, $definition) {}

    /**
     * @param string $name 
     * @return bool 
     */
    public function has($name) {}

    /**
     * @param string $name 
     * @return object 
     */
    public function get($name) {}

    /**
     * @param string $name 
     * @return object 
     */
    public function getService($name) {}

}
