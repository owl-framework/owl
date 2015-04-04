
namespace Owl\Router;

use Owl\Http\Request;
use Owl\Http\RequestInterface;

class Router implements RouterInterface
{
    protected basePath = "" {get, set};

    protected types = [
        "i"   : "[0-9]++",
        "int" : "[0-9]++",
		"*"   : ".+?",
		"**"  : ".++"
    ];

    protected routers = [];

    public function add(string uri, array! parameters = [], string method = Request::GET)
    {
        var route;

        if (strpos(uri, "{") === false && strpos(uri, ":") === false) {
            let route = new Http\StaticRoute;
        } else {
            let route = new Http\DynamicRoute;
        }

        let route->uri = uri;
        let route->method = method;
        let route->parameters = parameters;

        let this->routers[] = route;
    }

    public function addRoute(<Route> route)
    {
        let this->routers[] = route;
    }

    public function matchRequest(<RequestInterface> request)
    {
        return this->match(request->getUri(), request->getMethod());
    }

    inline public function match(string uri, string method = Request::GET) -> object|boolean
    {
        var router;

        for router in this->routers {
            if (router->match(uri) && (router->method == "all" || router->method == method)) {
                return router;
            }
        }

        return false;
    }
}
