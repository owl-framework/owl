<?php
/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

use Owl\Application;
use Owl\Http\Request;

$application = new Application();
$response = $application->handle(new Request());

var_dump($response);

class Router {

}

$serviceManager = new Owl\Service\Manager();
$serviceManager->setService('router', new Router());
var_dump($serviceManager->getService('router'));


$router = new \Owl\Router\Router();
$router->add("/", ['name' => 'default', 'action' => 'index', 'controller' => 'index', 'module' => 'index']);
$router->add("/user/1/", ['name' => 'user-view-static', 'action' => 'view', 'controller' => 'user', 'module' => 'user']);

var_dump($router->match("/"));

var_dump(\Owl\Annotations\Parser::parse("/**
* @Post
*/
"));