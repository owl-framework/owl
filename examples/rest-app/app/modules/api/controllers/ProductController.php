<?php
/**
 * @author Patsura Dmitry @ovr <talk@dmtry.me>
 */

namespace RestApp\Api\Controller;

use Exception;
use Flame\Connection;
use Flame\Grammar\MysqlGrammar;

/**
 * Class UserController
 * @Path("/api/products")
 */
class UserController extends \Owl\Mvc\Controller
{
    /**
     * @Get
     * @Url("/{id:int}/")
     */
    public function indexAction($id)
    {
        $flame = new Connection('mysql:dbname=hello_world', 'user', 'password', [], new MysqlGrammar());
        $stmt = $flame->prepare('SELECT * FROM users WHERE id = i:id)');
        $users = $stmt->execute(['id' => $_POST['id']]);


        return array(
            'data' => $this->users[$id]
        );
    }

    /**
     * @Get
     * @Url("/")
     */
    public function listAction()
    {
        return array(
            'data' => $this->users,
            'total' => count($this->users)
        );
    }
}