<?php

namespace Owl\Std;

class ArrayBag implements \Countable
{

    protected $elements;


    /**
     * @param array $input 
     */
    public function __construct($input) {}


    public function count() {}

    /**
     * @param string $key 
     * @param mixed $defaultValue 
     */
    public function get($key, $defaultValue = null) {}

}
