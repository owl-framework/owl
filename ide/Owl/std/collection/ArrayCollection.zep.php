<?php

namespace Owl\Std\Collection;

class ArrayCollection extends \Owl\Std\Collection\AbstractCollection
{

    protected $elements;


    /**
     * {@inheritDoc}
     *
     * @param array $elements 
     */
    public function __construct($elements = array()) {}

    /**
     * {@inheritDoc}
     *
     * @param mixed $element 
     */
    public function add($element) {}

    /**
     * Checks is collection empty?
     *
     * @return bool 
     */
    public function isEmpty() {}

    /**
     * {@inheritDoc}
     *
     * @param mixed $func 
     */
    public function map(\Closure $func) {}

    /**
     * {@inheritDoc}
     *
     * @param mixed $func 
     */
    public function filter($func) {}

    /**
     * {@inheritDoc}
     */
    public function first() {}

    /**
     * {@inheritDoc}
     */
    public function last() {}

    /**
     * {@inheritDoc}
     *
     * @return \ArrayIterator 
     */
    public function getIterator() {}

    /**
     * {@inheritDoc}
     *
     * @return int 
     */
    public function count() {}

}
