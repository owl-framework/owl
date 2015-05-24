<?php
/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

namespace RestApp\Api\Controller;

use Exception;

/**
 * Class ProductController
 * @Path("/api/products")
 */
class ProductController extends \Owl\Mvc\Controller
{
    /**
     * @Get
     * @Url("/{id:int}/")
     */
    public function indexAction($id)
    {
        throw new Exception('Not implemented', 500);
    }

    /**
     * @Get
     * @Url("/")
     */
    public function listAction()
    {
        throw new Exception('Not implemented', 500);
    }
}
