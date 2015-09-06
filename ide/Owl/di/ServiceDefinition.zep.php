<?php

namespace Owl\Di;


class ServiceDefinition implements \Owl\Di\ServiceDefinitionInterface
{
    /**
     * @var string
     */
    protected $name;

    /**
     * @var object|callable
     */
    protected $definition;

    /**
     * @var boolean
     */
    protected $shared = false;

    /**
     * @var boolean
     */
    protected $resolved = false;


    /**
     * @return string 
     */
    public function getName() {}

    /**
     * @return object|callable 
     */
    public function getDefinition() {}

    /**
     * @return boolean 
     */
    public function getShared() {}

    /**
     * @return boolean 
     */
    public function getResolved() {}

    /**
     * Phalcon\Di\Service
     *
     * @param string $name 
     * @param mixed $definition 
     * @param boolean $shared 
     */
    public final function __construct($name, $definition, $shared = false) {}

}
