<?php

namespace Owl;

interface ApplicationInterface
{

    const ENV_PRODUCTION = "production";


    const ENV_DEVELOPMENT = "development";


    const EVENT_BEFORE_HANDLE = "beforeHandle";


    const EVENT_AFTER_HANDLE = "afterHandle";


    /**
     * @param mixed $di 
     * @param mixed $eventManager 
     * @param string $env 
     */
	public function __construct(\Owl\Service\Manager $di = null, Event\Manager $eventManager = null, $env = self::ENV_PRODUCTION);

    /**
     * Handle Http Request
     *
     * @param mixed $request 
     * @param mixed $response 
     * @return \Owl\Http\Response 
     */
	public function handle(\Owl\Http\RequestInterface $request, \Owl\Http\Response $response = null);

}
