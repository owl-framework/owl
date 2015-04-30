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

$serviceManager = new Owl\Service\Manager();

$router = new Router();
$router->add('/', ['module' => 'Common', 'controller' => 'Index', 'action' => 'index']);

$serviceManager->setService('router', $router);

$driver = new \Owl\DBAl\Driver\Mysql(
    'mysql:host=127.0.0.1;dbname=phalcon-module-skeleton;port=49153',
    'root',
    'root',
    array(
        PDO::ATTR_PERSISTENT => true, // OMG Is so impossible :D
        PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES "UTF8"'
    )
);
$connection = new \Owl\DBAL\Connection(['driver' => $driver], $eventManager);
$serviceManager->setService('connection', $connection);

$cache = new \Owl\Cache\Driver\Memcached();
$serviceManager->setService('cache', $cache);

$application = new Application($serviceManager, $eventManager);
$response = $application->handle(Request::createFromGlobals(), new \Owl\Http\Response\Json());

$response = $profiler->setContent($response);
$response->send();
