<?php
/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

use Owl\Application;
use Owl\Http\Request;
use Owl\Router\Route;
use Owl\Router\Router;

error_reporting(-1);
ini_set('display_errors', 1);

include_once __DIR__ . '/../vendor/autoload.php';

$eventManager = new \Owl\Event\Manager();

$profiler = new Owl\Debug\Profiler();
$profiler->setAssetsUri('//assets.owl.local/profiler/min.css');
$profiler->listen($eventManager);

$di = new Owl\Di\Container();

$router = new Router();
$router->add('/', ['module' => 'Common', 'controller' => 'Index', 'action' => 'index']);

$di->set('router', $router);

$driver = new \Owl\DBAl\Driver\Mysql(
    'mysql:host=127.0.0.1;dbname=phalcon-module-skeleton;port=49153',
    'root',
    'root',
    array(
        PDO::ATTR_PERSISTENT => true, // OMG It's so impossible :D
        PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES "UTF8"'
    )
);
$connection = new \Owl\DBAL\Connection(['driver' => $driver], $eventManager);
$di->set('connection', $connection);

$cache = new \Owl\Cache\Driver\Memcached();
$di->set('cache', $cache);

$view = new \Owl\Mvc\View();
$view->setPath(__DIR__ . '/../app/modules/common/resources/views/');
$di->set('view', $view);

$application = new Application($di, $eventManager);
$application->setErrorHandlerParameters(array(
    'module' => 'Common',
    'controller' => 'Index',
    'action' => 'error'
));
$application->setExceptionHandlerParameters(array(
    'module' => 'Common',
    'controller' => 'Index',
    'action' => 'exception'
));
$response = $application->handle(Request::createFromGlobals(), new \Owl\Http\Response());

$response = $profiler->setContent($response);
$response->send();
