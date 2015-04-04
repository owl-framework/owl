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

/**
 * Frontend
 */
$router->add('/', ['module' => 'Frontend', 'controller' => 'Index', 'action' => 'index']);

/**
 * Api module - REST API
 */
$router->add('/api', ['module' => 'Api', 'controller' => 'Index', 'action' => 'index']);
$router->add('/api/users', ['module' => 'Api', 'controller' => 'User', 'action' => 'list']);
$router->add('/api/users/:id', ['module' => 'Api', 'controller' => 'User', 'action' => 'index']);
$router->add('/api/users/:id', ['module' => 'Api', 'controller' => 'User', 'action' => 'create'], Route::POST);
$router->add('/api/users/:id', ['module' => 'Api', 'controller' => 'User', 'action' => 'delete'], Route::DELETE);

$serviceManager->setService('router', $router);

$application = new Application($serviceManager);
$response = $application->handle(Request::createFromGlobals());
$response->send();
