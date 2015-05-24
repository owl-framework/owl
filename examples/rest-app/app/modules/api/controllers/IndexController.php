<?php
/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

namespace RestApp\Api\Controller;

use Exception;
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
        /** @var \Owl\DBAL\Connection $connection */
        $connection = $this->di->get('connection');

//        var_dump($_SERVER);
        var_dump($this->request->getServer('HTTP_USER_AGENT'));
        var_dump($this->request->getServer('HTTP_ACCEPT_LANGUAGE'));
        var_dump($this->request->getServer('REQUEST_TIME'));
        var_dump($this->request->getServer('SERVER_PROTOCOL'));
        var_dump($this->request->getServer('REMOTE_ADDR'));

//        $connection->insert('views', [
//            'HTTP_USER_AGENT' =
//        ]);


//        $statement = $connection->prepare("SELECT * FROM `phalcon-module-skeleton`.User__Users;");
//        $statement->execute();
//
//
//        $cache->save('users', $statement->fetchAll(), 3600);
//
//        return $statement->fetchAll();


        $response = new \Owl\Http\Response();
        $response->setContent('html encode');

        return $response;
//        return array(
//            'info' => array(
//                'php' => array(
//                    'version' => PHP_VERSION
//                ),
//                'time' => time()
//            )
//        );
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

    public function errorAction()
    {
        return array(
            'message' => 'Not found',
            'uri' => $this->request->getUri()
        );
    }

    public function exceptionAction(Exception $e)
    {
        if ($e->getCode() >= 400) {
            $this->response->setCode($e->getCode());
        }

        return array(
            $e->getMessage()
        );
    }
}
