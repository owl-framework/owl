<?php
/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */


use Owl\Application;
use Owl\Http\Request;

$serviceManager = new Owl\Service\Manager();
$serviceManager->set('router', new \Owl\Router\Router());
var_dump($serviceManager->getInstance('router'));

$application = new Application($serviceManager);
$response = $application->handle(Request::createFromGlobals());
var_dump($response);

$router = new \Owl\Router\Router();
$router->add("/", ['name' => 'default', 'action' => 'index', 'controller' => 'index', 'module' => 'index']);
$router->add("/user/1/", ['name' => 'user-view-static', 'action' => 'view', 'controller' => 'user', 'module' => 'user']);

var_dump($router->match("/"));
var_dump($router->match("/user/1/"));

var_dump(
    \Owl\Annotations\Reader::parse('
        /**
         * @Post
         * @Url("/user/:id/")
         */
    ')
);
