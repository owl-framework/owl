<?php
/**
 * @author Patsura Dmitry @ovr <talk@dmtry.me>
 */

/**
 * Class IndexController
 * @Path("/api/")
 */
class IndexController extends \Owl\Rest\Controller
{
    /**
     * @Get
     * @Url("/user/{id:int}/")
     */
    public function indexAction($id)
    {
        return array(
            'user' => array(
                'id' => $id
            )
        );
    }

    /**
     * @Post
     * @Url("/user/{id:int}/")
     */
    public function createAction()
    {
        //Create new user in db

        return true;
    }

    /**
     * @Delete
     * @Url("/user/{id:int}/")
     */
    public function deleteAction()
    {
        //Remove user from db

        return true;
    }
}