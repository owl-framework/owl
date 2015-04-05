
namespace Owl;

use Owl\Service\Manager;

use Owl\Http\Request;
use Owl\Http\RequestInterface;
use Owl\Http\Response;

use Owl\Router\Http\StaticRoute;

class Application
{
    const ENV_PRODUCTION = "production";
    const ENV_DEVELOPMENT = "development";

    /**
     * @var \Owl\Http\RequestInterface
     */
    protected request {get};

    /**
     * @var \Owl\Http\Response
     */
    protected response {get};

    /**
     * @var \Owl\Service\Manager
     */
    protected di {get};

    /**
     * Current env, see ENV_* constants
     *
     * @var string
     */
    protected env {get};

    protected currentLoop = 0;
    
    public fn __construct(<Manager> di = null, string env = self::ENV_PRODUCTION)
    {
        let this->di = di;
        let this->env = env;
    }

    inline protected fn dispatch(var parameters, var matchedRoute, var response)
    {
        var handlerClass, controller, result, action, e;

        let this->currentLoop++;

        let handlerClass = "\\RestApp" . "\\" . parameters["module"] . "\\Controller\\" . parameters["controller"] . "Controller";
        let action = parameters["action"] . "Action";

        if (this->currentLoop > 3) {
            response->setContent("World was crashed");
            response->setCode(500);

            return false;
        }

        try {
            if (!class_exists(handlerClass)) {
                throw new Exception("Class handler: '" . handlerClass . "' is not exists");
            }

            let controller = new {handlerClass}(this->request, response);

            if (matchedRoute instanceof StaticRoute) {
                let result = controller->{action}();
            } else {
                /**
                 * @todo It's not a performance, 7200 vs 8300 RPS, maybe only request parameters?
                 */
                let result = call_user_func_array([controller, action], matchedRoute->uriParameters);
            }

            response->setContent(result);
        } catch Exception, e {
            response->setCode(500);
            this->dispatch(parameters, matchedRoute, response);
        }
    }

    /**
     * Handle Http Request
     */
    public fn handle(<RequestInterface> request, <Response> response = null) -> <Response>
    {
        var matchedRoute, router;

        if (is_null(response)) {
            let response = new Response();
        }
        
        let router = this->di->get("router");
        let matchedRoute = router->matchRequest(request);

        if (matchedRoute) {
            var parameters;
            let parameters = matchedRoute->parameters;

            let this->request = request;
            this->dispatch(parameters, matchedRoute, response);
        } else {
            response->setCode(404);
            this->dispatch(parameters, matchedRoute, response);
        }

        return response;
    }
}
