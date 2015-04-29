<?php
/**
 * @author Patsura Dmitry @ovr <talk@dmtry.me>
 */

namespace RestApp\Api\Controller;

/**
 * Class IndexController
 * @Path("/api")
 */
class IndexController extends \Owl\Mvc\Controller
{
    /**
     * @Get
     * @Url("/", name="default")
     */
    public function indexAction()
    {
        /** @var \Owl\DBAL\Driver\MySQL $connection */
        $connection = $this->di->get('connection');
        $statement = $connection->prepare("SELECT * FROM `phalcon-module-skeleton`.User__Users;");
        $statement->execute();

        return $statement->fetchAll();

        return array(
            'info' => array(
                'php' => array(
                    'version' => PHP_VERSION
                ),
                'time' => time()
            )
        );
    }

    public function exceptionAction()
    {
        return array(
            'Exception was corrupted'
        );
    }
}
