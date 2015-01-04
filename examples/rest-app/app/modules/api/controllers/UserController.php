<?php
/**
 * @author Patsura Dmitry @ovr <talk@dmtry.me>
 */

/**
 * Class UserController
 * @Path("/api/")
 */
class UserController extends \Owl\Rest\Controller
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
     * @Get
     * @Url("/users")
     */
    public function listAction()
    {
        //Get users from db

        return true;
    }

    /**x
     * @Post
     * @Url("/user")
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