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
$router->add('/users/:id', ['module' => 'Api', 'controller' => 'User', 'action' => 'create'], Route::DELETE);

$serviceManager->setService('router', $router);

$application = new Application($serviceManager);
$response = $application->handle(Request::createFromGlobals());

var_dump($response);
