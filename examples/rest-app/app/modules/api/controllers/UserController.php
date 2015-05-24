<?php
/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

namespace RestApp\Api\Controller;

use Exception;

/**
 * Class UserController
 * @Path("/api")
 */
class UserController extends \Owl\Mvc\Controller
{
    protected $users = array(
        1 => array(
            'id' => 1,
            'firstname' => 'Dmitry',
            'lastname' => 'Patsura',
            'nick' => 'ovr'
        ),
        2 => array(
            'id' => 2,
            'firstname' => 'Sergey',
            'lastname' => 'Ilin',
            'nick' => 'serebro'
        ),
        3 => array(
            'id' => 3,
            'firstname' => 'Nikolay',
            'lastname' => 'Kirsh',
            'nick' => 'xboston'
        )
    );

    /**
     * @Get
     * @Url("/user/{id:int}/")
     */
    public function indexAction($id)
    {
        if (!isset($this->users[$id])) {
            throw new Exception('User with id = ' . $id . ' is not exists', 404);
        }

        return array(
            'data' => $this->users[$id]
        );
    }

    /**
     * @Get
     * @Url("/users")
     */
    public function listAction()
    {
        return array(
            'data' => $this->users,
            'total' => count($this->users)
        );
    }

    /**x
     * @Post
     * @Url("/user")
     */
    public function createAction()
    {
        return array(
            'data' => array(
                'message' => 'Thanks'
            )
        );
    }

    /**
     * @Delete
     * @Url("/user/{id:int}/")
     */
    public function deleteAction()
    {
        return array(
            'data' => array(
                'message' => 'No no no no'
            )
        );
    }
}
