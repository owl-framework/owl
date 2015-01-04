<?php


$serviceManager = new \Owl\Service\Manager();

$router = new \Owl\Router\Router();

$router->add('/', ['action' => '/']);
$router->add('/user/{id:int}/', ['action' => 'view']);
$router->add('/users', ['action' => 'users']);

$serviceManager->setService('router', $router);

$application = new \Owl\Application($serviceManager);
$application->handle(\Owl\Http\Request::createFromGlobals(), new \Owl\Http\Response());
