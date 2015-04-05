<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

use Owl\Application;
use Owl\Http\Request;
use Owl\Router\Router;

class ApplicationTest extends \PHPUnit_Framework_TestCase
{
    protected function createSmallApp()
    {
        $serviceManager = new Owl\Service\Manager();

        $router = new Router();
        $router->add('/', ['module' => 'Api', 'controller' => 'Index', 'action' => 'index']);

        $serviceManager->setService('router', $router);

        return new Application($serviceManager);
    }

    public function testCreateSmallApp()
    {
        $application = $this->createSmallApp();

        $this->assertInstanceOf('Owl\Application', $application);
        $this->assertInstanceOf('Owl\Service\Manager', $application->getDi());
        $this->assertSame(Application::ENV_PRODUCTION, $application->getEnv());
    }

    public function testHandle()
    {
        $application = $this->createSmallApp();
        $response = $application->handle(Request::createFromGlobals(), new \Owl\Http\Response\Json());

        $this->assertInstanceOf('Owl\Http\ResponseInterface', $response);
    }
} 