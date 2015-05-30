<?php
/**
 * @author: Patsura Dmitry @ovr <talk@dmtry.me>
 */

namespace Owl\Tests\View;

use Owl\Tests\TestCase;

/**
 * Class TestCase
 */
class EngineTest extends TestCase
{
    public function testSimple()
    {
        $view = new \Owl\Mvc\View();
        $view->setPath(__DIR__ . '/../../app/resources/views/');

        $this->assertSame("Hello, World!\n", $view->render('static.phtml'));
    }
}
