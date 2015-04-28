<?php
/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

use Owl\Application;
use Owl\Http\Request;
use Owl\Router\Route;
use Owl\Router\Router;


//$startTime = microtime(true);

include_once __DIR__ . '/../vendor/autoload.php';

$eventManager = new \Owl\Event\Manager();

$profiler = new Owl\Debug\Profiler();
$profiler->listen($eventManager);

$serviceManager = new Owl\Service\Manager();

$router = new Router();
$router->add('/', ['module' => 'Api', 'controller' => 'Index', 'action' => 'index']);
$router->add('/users', ['module' => 'Api', 'controller' => 'User', 'action' => 'list']);
$router->add('/users/:id', ['module' => 'Api', 'controller' => 'User', 'action' => 'index']);
$router->add('/users/:id', ['module' => 'Api', 'controller' => 'User', 'action' => 'create'], Route::POST);
$router->add('/users/:id', ['module' => 'Api', 'controller' => 'User', 'action' => 'delete'], Route::DELETE);

$serviceManager->setService('router', $router);

//$eventManager->listen(\Owl\ApplicationInterface::EVENT_BEFORE_HANDLE, function() use(&$startTime) {
//    printf('Before handle %.4F сек. <br/>', microtime(true)-$startTime);
//});
//
//$eventManager->listen(\Owl\ApplicationInterface::EVENT_AFTER_HANDLE, function() use(&$startTime) {
//    printf('Handle on %.4F сек. <br/>', microtime(true)-$startTime);
//});

$application = new Application($serviceManager, $eventManager);
$response = $application->handle(Request::createFromGlobals(), new \Owl\Http\Response\Json());

$response = $profiler->setContent($response);
$response->send();
