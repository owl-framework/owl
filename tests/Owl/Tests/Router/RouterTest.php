<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

class RouterTest extends \PHPUnit_Framework_TestCase
{
    public function testGetFixtures()
    {
        $router = new \Owl\Router\Router();
        $router->add("/", ['name' => 'default', 'action' => 'index', 'controller' => 'index', 'module' => 'index']);
        $router->add("/user/1/", ['name' => 'user-view-static', 'action' => 'view', 'controller' => 'user', 'module' => 'user']);

        $this->assertInstanceOf('Owl\Router\Route', $router->match("/"));
    }
} 