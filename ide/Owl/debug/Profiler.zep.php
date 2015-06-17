<?php

namespace Owl\Debug;


class Profiler
{

    protected $startTime;


    protected $lastTime;


    protected $assetsUri = "//owl-framework.github.io/assets/profiler/min.css";



    public function getAssetsUri() {}

    /**
     * @param mixed $assetsUri 
     */
    public function setAssetsUri($assetsUri) {}


    public function __construct() {}

    /**
     * @param mixed $event 
     */
    public function logEvent(\Owl\Event\Event $event) {}

    /**
     * @param mixed $em 
     */
    public function listen(\Owl\Event\Manager $em) {}

    /**
     * @param mixed $response 
     * @return \Owl\Http\ResponseInterface 
     */
    public function setContent(\Owl\Http\ResponseInterface $response) {}

}
