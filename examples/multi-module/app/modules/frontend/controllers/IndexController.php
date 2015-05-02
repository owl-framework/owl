<?php
/**
 * @author Patsura Dmitry @ovr <talk@dmtry.me>
 */

namespace RestApp\Frontend\Controller;

use Owl\Mvc\Controller;

/**
 * Class IndexController
 * @Path("/")
 */
class IndexController extends Controller
{
    /**
     * @Get
     * @Url("/", name="default")
     */
    public function indexAction()
    {

    }
}
