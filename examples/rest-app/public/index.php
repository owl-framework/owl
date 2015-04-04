<?php
/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

use Owl\Application;
use Owl\Http\Request;
use Owl\Router\Route;
use Owl\Router\Router;

$serviceManager = new Owl\Service\Manager();

$router = new Router();
$router->add('/', ['module' => 'api', 'controller' => 'index', 'action' => 'default']);
$router->add('/users', ['module' => 'api', 'controller' => 'user', 'action' => 'list']);
$router->add('/users/:id', ['module' => 'api', 'controller' => 'user', 'action' => 'index']);
$router->add('/users/:id', ['module' => 'api', 'controller' => 'user', 'action' => 'create'], Route::POST);
$router->add('/users/:id', ['module' => 'api', 'controller' => 'user', 'action' => 'create'], Route::DELETE);

$serviceManager->setService('router', $router);

$application = new Application($serviceManager);
$response = $application->handle(Request::createFromGlobals());

var_dump($response);
