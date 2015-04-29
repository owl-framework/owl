<?php
/**
 * @author Patsura Dmitry @ovr <talk@dmtry.me>
 */

namespace RestApp\Api\Controller;

use ReflectionExtension;

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
//        /** @var \Owl\Cache\Driver $cache */
//        $cache = $this->di->get('cache');
//
//        return $cache->get('users');
//
//        /** @var \Owl\DBAL\Driver\MySQL $connection */
//        $connection = $this->di->get('connection');
//        $statement = $connection->prepare("SELECT * FROM `phalcon-module-skeleton`.User__Users;");
//        $statement->execute();
//
//
//        $cache->save('users', $statement->fetchAll(), 3600);
//
//        return $statement->fetchAll();

        return array(
            'info' => array(
                'php' => array(
                    'version' => PHP_VERSION
                ),
                'time' => time()
            )
        );
    }

    /**
     * @Get
     * @Url("/ping", name="api-ping")
     */
    public function pingAction()
    {
        return ['pong'];
    }

    /**
     * @Get
     * @Url("/version", name="api-show-version")
     */
    public function versionAction()
    {
        $ext = new ReflectionExtension('owl');

        return [
            'version' => '0.1-dev',
            'owl' => $ext->getVersion()
        ];
    }

    public function exceptionAction()
    {
        return array(
            'Exception was corrupted'
        );
    }
}
