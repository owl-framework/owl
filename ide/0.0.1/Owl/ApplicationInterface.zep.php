<?php

namespace Owl;

interface ApplicationInterface
{

    const ENV_PRODUCTION = "production";


    /**
     * @param mixed $di 
     * @param mixed $eventManager 
     * @param string $env 
     */
	public function __construct(Manager $di = null, Event\Manager $eventManager = null, $env = self::ENV_PRODUCTION);

    /**
     * Handle Http Request
     *
     * @param mixed $request 
     * @param mixed $response 
     * @return Response 
     */
	public function handle(RequestInterface $request, Response $response = null);

}
