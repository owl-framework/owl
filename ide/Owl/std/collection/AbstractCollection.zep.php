<?php

namespace Owl\Std\Collection;


abstract class AbstractCollection implements \Countable, \IteratorAggregate
{

    /**
     * Get elements count from a collection
     */
    abstract public function count();

    /**
     * Get iterator
     */
    abstract public function getIterator();

    /**
     * Execute a function on each element in the collection
     *
     * @param mixed $func 
     */
    abstract public function map(\Closure $func);

    /**
     * Execute a function on each element in the collection and
     * removes the element from the collection if the executed function returns false
     *
     * @param mixed $func 
     */
    abstract public function filter($func);

    /**
     * Set the current element to the first element and returns it
     */
    abstract public function first();

    /**
     * Set current element to the last element and returns it
     */
    abstract public function last();

    /**
     * Add a element to the collection
     *
     * @param mixed $element 
     */
    abstract public function add($element);

}
