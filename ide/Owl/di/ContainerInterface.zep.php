<?php

namespace Owl\Di;


interface ContainerInterface
{

    /**
     * @param string $name 
     * @param mixed $definition 
     */
    public function setService($name, $definition);

    /**
     * @param string $name 
     * @param mixed $definition 
     */
    public function set($name, $definition);

    /**
     * @param string $name 
     * @return bool 
     */
    public function has($name);

    /**
     * @param string $name 
     * @return object 
     */
    public function get($name);

    /**
     * @param string $name 
     * @return object 
     */
    public function getService($name);

}
