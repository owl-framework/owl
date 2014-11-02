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


