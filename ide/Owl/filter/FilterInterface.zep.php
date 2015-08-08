<?php

namespace Owl\Filter;


interface FilterInterface
{

    /**
     * Returns the result of filtering $value
     *
     * @param mixed $value 
     * @return mixed 
     */
    public function filter($value);

}
