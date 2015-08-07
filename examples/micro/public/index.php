<?php


$di = new Owl\Di\Container();
$router = new \Owl\Router\Router();

$router->add('/', ['action' => '/']);
$router->add('/user/{id:int}/', ['action' => 'view']);
$router->add('/users', ['action' => 'users']);

$di->set('router', $router);

$application = new \Owl\Application($di);
$application->handle(\Owl\Http\Request::createFromGlobals(), new \Owl\Http\Response());
