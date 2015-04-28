<?php

namespace Owl\Session;

interface ManagerInterface
{

    /**
     * @return bool 
     */
    public function start();

    /**
     * @return string 
     */
    public function getId();

    /**
     * @param int $ttl 
     */
    public function rememberMe($ttl);


    public function forgetMe();

}
