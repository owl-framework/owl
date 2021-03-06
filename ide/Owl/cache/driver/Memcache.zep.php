<?php

namespace Owl\Cache\Driver;

/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */
class Memcache extends \Owl\Cache\Driver\CacheDriver
{

    protected $options;

    /**
     * @var \Memcache
     */
    protected $instance;


    /**
     * @param array $options 
     */
    public function __construct($options = null) {}

    /**
     * @param mixed $instance 
     */
    public function setInstance(\Memcache $instance) {}

    /**
     * @return \Memcache 
     */
    public function getInstance() {}


    public function __destruct() {}

    /**
     * {@inheritDoc}
     *
     * @param mixed $id 
     * @param mixed $data 
     * @param mixed $lifeTime 
     */
    public function save($id, $data, $lifeTime = 3600) {}

    /**
     * {@inheritDoc}
     *
     * @param mixed $id 
     */
    public function delete($id) {}

    /**
     * {@inheritDoc}
     *
     * @param mixed $id 
     */
    public function get($id) {}

    /**
     * {@inheritDoc}
     */
    public function flush() {}

}
