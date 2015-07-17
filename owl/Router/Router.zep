
namespace Owl\Router;

use Owl\Http\Request;
use Owl\Http\RequestInterface;

class Router implements RouterInterface
{
    protected basePath = "" {get, set};

    protected routers = [];

    public function add(string uri, array! parameters = [], string method = Request::GET)
    {
        var route;

        if (strpos(uri, "{") === false && strpos(uri, ":") === false) {
            let route = new Http\StaticRoute(uri);
        } else {
            let route = new Http\DynamicRoute(uri);
        }

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
    	var result, path;
    	let result = parse_url(request->getUri());

		if fetch path, result["path"] {
        	return this->match(path, request->getMethod());
		}

		throw new \Owl\Exception("Cannot fetch path from request");
    }

    inline public function match(string uri, string method = Request::GET) -> object|boolean
    {
        var router;

        for router in this->routers {
            if (router->match(uri) && (router->method == Route::ALL || router->method == method)) {
                return router;
            }
        }

        return false;
    }
}
