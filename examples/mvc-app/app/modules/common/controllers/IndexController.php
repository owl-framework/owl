<?php
/**
 * @author Patsura Dmitry @ovr <talk@dmtry.me>
 */

namespace RestApp\Common\Controller;

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
        /** @var \Owl\Mvc\View $view */
        $view = $this->di->get('view');
        return $view->render('index/index.phtml', null);
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
            $this->response->setStatusCode($e->getCode());
        }

        return array(
            $e->getMessage()
        );
    }
}
