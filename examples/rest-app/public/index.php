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
include_once __DIR__ . '/../app/Application.php';

$eventManager = new \Owl\Event\Manager();

$profiler = new Owl\Debug\Profiler();
$profiler->listen($eventManager);

$application = new \RestApp\Application(new Owl\Service\Manager(), $eventManager);
$response = $application->bootstrap()->handle(Request::createFromGlobals(), new \Owl\Http\Response\Json());

$response = $profiler->setContent($response);
$response->send();
