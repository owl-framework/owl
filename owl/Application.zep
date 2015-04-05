
namespace Owl;

use Owl\Service\Manager;

use Owl\Http\Request;
use Owl\Http\RequestInterface;
use Owl\Http\Response;

class Application
{
    const ENV_PRODUCTION = "production";
    const ENV_DEVELOPMENT = "development";

    protected request {get};

    protected response {get};

    protected di {get};

    protected env {get};
    
    public fn __construct(<Manager> di = null, string env = self::ENV_PRODUCTION)
    {
        let this->di = di;
        let this->env = env;
    }

    /**
     * Handle Http Request
     */
    public fn handle(<RequestInterface> request, <Response> response = null) -> <Response>
    {
        var matchedRoute, router, e;

        if (is_null(response)) {
            let response = new Response();
        }
        
        let router = this->di->get("router");
        let matchedRoute = router->matchRequest(request);

        if (matchedRoute) {
            var handlerClass, controller, result, action;

            let handlerClass = "\\RestApp" . "\\" . matchedRoute->parameters["module"] . "\\Controller\\" . matchedRoute->parameters["controller"] . "Controller";
            let action = matchedRoute->parameters["action"] . "Action";

            try {
                let controller = new {handlerClass};
                let result = controller->{action}(request, response);

                response->setContent(result);
            } catch Exception, e {
                response->setCode(500);
            }
        } else {
            response->setCode(404);
        }

        return response;
    }
}
