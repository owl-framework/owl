<?php

namespace Owl\Std;


class ArrayBag implements \Countable
{

    protected $elements;


    /**
     * @param array $input 
     */
    public function __construct($input) {}

    /**
     * @return int 
     */
    public function count() {}

    /**
     * @param string $key 
     * @param mixed $value 
     */
    public function set($key, $value) {}

    /**
     * @param string $key 
     * @return bool 
     */
    public function has($key) {}

    /**
     * @param string $key 
     * @param mixed $defaultValue 
     * @return variable 
     */
    public function get($key, $defaultValue = null) {}

}
