<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

class RouterTest extends \PHPUnit_Framework_TestCase
{
    public function testGetFixturesStatic()
    {
        $router = new \Owl\Router\Router();

        $router->add("/", ['name' => 'default', 'action' => 'index', 'controller' => 'index', 'module' => 'index']);
        $router->add("/user/1/", ['name' => 'user-view-static-1', 'action' => 'view', 'controller' => 'user', 'module' => 'user']);
        $router->add("/user/100/", ['name' => 'user-view-static-100', 'action' => 'view', 'controller' => 'user', 'module' => 'user']);

        $this->assertInstanceOf('Owl\Router\Route', $result = $router->match("/"));
        $this->assertSame("default", $result->parameters["name"]);

        $this->assertFalse($router->match("/user/50/"));
        $this->assertFalse($router->match("/user/100/a"));

        $this->assertInstanceOf('Owl\Router\Route', $result = $router->match("/user/1/"));
        $this->assertSame("user-view-static-1", $result->parameters["name"]);

        $this->assertInstanceOf('Owl\Router\Route', $result = $router->match("/user/100/"));
        $this->assertSame("user-view-static-100", $result->parameters["name"]);

        $this->assertFalse($router->match('/not-found-route'));
    }

    public function testGetFixturesDynamic()
    {
        $router = new \Owl\Router\Router();
        $router->add("/", ['name' => 'default', 'action' => 'index', 'controller' => 'index', 'module' => 'index']);
        $router->add("/user/:id/", ['name' => 'user-view', 'action' => 'view', 'controller' => 'user', 'module' => 'user']);

        $this->assertInstanceOf('Owl\Router\Route', $result = $router->match("/"));
        $this->assertSame("default", $result->parameters["name"]);

        $this->assertInstanceOf('Owl\Router\Route', $result = $router->match("/user/1/"));
        $this->assertSame("user-view", $result->parameters["name"]);

        $this->assertInstanceOf('Owl\Router\Route', $result = $router->match("/user/100/"));
        $this->assertSame("user-view", $result->parameters["name"]);

        $this->assertFalse($router->match("/user/f/"));
        $this->assertFalse($router->match("/user/0f/"));
        $this->assertFalse($router->match("/user/0ads/"));

        $this->assertFalse($router->match('/not-found-route'));

        $router->add("/ur/:id", ['name' => 'ur-view', 'action' => 'view', 'controller' => 'user', 'module' => 'user']);

        $this->assertInstanceOf('Owl\Router\Route', $result = $router->match("/ur/1"));
        $this->assertSame("ur-view", $result->parameters["name"]);

        $this->assertInstanceOf('Owl\Router\Route', $result = $router->match("/ur/100"));
        $this->assertSame("ur-view", $result->parameters["name"]);

        $this->assertFalse($router->match("/ur/1/")); //rly?

        $this->assertFalse($router->match("/ur/f/"));
        $this->assertFalse($router->match("/ur/0f/"));
        $this->assertFalse($router->match("/ur/0ads/"));


        $router->add("/usr/id:int/", ['name' => 'user-view-int', 'action' => 'view', 'controller' => 'user', 'module' => 'user']);

        $this->assertInstanceOf('Owl\Router\Route', $result = $router->match("/usr/1/"));
        $this->assertSame('user-view-int', $result->parameters["name"]);

        $this->assertInstanceOf('Owl\Router\Route', $result = $router->match("/usr/100/"));
        $this->assertSame('user-view-int', $result->parameters["name"]);

        $this->assertFalse($router->match("/usr/f/"));
        $this->assertFalse($router->match("/usr/0f/"));
        $this->assertFalse($router->match("/usr/0ads/"));
    }
}
