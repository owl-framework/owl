<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace RestApp\Controller;

class IndexController extends \Owl\Mvc\Controller
{
    public function indexAction()
    {
        return array(
            'test' => 1,
            'key' => 'value'
        );
    }
}
