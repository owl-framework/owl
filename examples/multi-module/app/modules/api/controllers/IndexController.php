<?php
/**
 * @author Patsura Dmitry @ovr <talk@dmtry.me>
 */

namespace RestApp\Api\Controller;

use Owl\Mvc\Controller;

/**
 * Class IndexController
 * @Path("/api")
 */
class IndexController extends Controller
{
    /**
     * @Get
     * @Url("/", name="default")
     */
    public function indexAction()
    {
        return array(
            'info' => array(
                'php' => array(
                    'version' => PHP_VERSION
                ),
                'time' => time()
            )
        );
    }
}
