<?php
/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

use Owl\Application;
use Owl\Http\Request;
use Owl\Router\Route;
use Owl\Router\Router;

include_once __DIR__ . '/../vendor/autoload.php';

$serviceManager = new Owl\Service\Manager();

$router = new Router();
$router->add('/', ['module' => 'Api', 'controller' => 'Index', 'action' => 'index']);
$router->add('/users', ['module' => 'Api', 'controller' => 'User', 'action' => 'list']);
$router->add('/users/:id', ['module' => 'Api', 'controller' => 'User', 'action' => 'index']);
$router->add('/users/:id', ['module' => 'Api', 'controller' => 'User', 'action' => 'create'], Route::POST);
$router->add('/users/:id', ['module' => 'Api', 'controller' => 'User', 'action' => 'delete'], Route::DELETE);

$serviceManager->setService('router', $router);

$eventManager = new \Owl\Event\Manager();
$eventManager->listen('dispatch:afterInitialize', function($app) {
    var_dump('dispatch:afterInitialize');
});

$eventManager->listen('dispatch:afterAction', function($app) {
    var_dump('dispatch:afterAction');
});

$eventManager->listen('dispatch:afterAction', function($app) {
    var_dump('dispatch:afterAction');
});

$eventManager->listen('dispatch:beforeExecuteRoute', function($app) {
    var_dump('dispatch:beforeExecuteRoute');
});

$eventManager->listen('dispatch:beforeExecuteRoute', function($app) {
    var_dump('dispatch:beforeExecuteRoute');
});

$eventManager->listen('dispatch:afterExecuteRoute', function($app) {
    var_dump('dispatch:afterExecuteRoute');
});

$eventManager->listen('app:afterHandle', function($app) {
    var_dump('app:afterHandle');
});

$application = new Application($serviceManager, $eventManager);
$response = $application->handle(Request::createFromGlobals(), new \Owl\Http\Response\Json());
$response->send();
