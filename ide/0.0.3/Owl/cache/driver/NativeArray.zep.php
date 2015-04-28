<?php

namespace Owl\Cache\Driver;

class NativeArray extends \Owl\Cache\Driver\CacheDriver
{

    protected $options;

    /**
     * @var array|null
     */
    protected $instance;


    /**
     * @param array $options 
     */
    public function __construct($options = null) {}

    /**
     * @param array $instance 
     */
    public function setInstance($instance) {}

    /**
     * @return array 
     */
    public function getInstance() {}


    public function __destruct() {}

    /**
     * {@inheritDoc}
     *
     * @param mixed $id 
     * @param mixed $data 
     * @param mixed $lifetime 
     */
    public function save($id, $data, $lifetime = 3600) {}

    /**
     * {@inheritDoc}
     *
     * @param mixed $id 
     */
    public function delete($id) {}

    /**
     * {@inheritDoc}
     *
     * @param string $id 
     */
    public function get($id) {}

    /**
     * {@inheritDoc}
     */
    public function flush() {}

}
