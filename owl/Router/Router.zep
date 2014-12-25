
namespace Owl\Router;

class Router implements RouterInterface
{
    protected basePath = "" {get, set};

    protected routers = [];

    public function add(string uri, string method = "GET")
    {
        var route;

        let route = new Route;
        let route->uri = uri;
        let route->method = method;

        let this->routers[] = route;
    }

    public function matchRequest(<Owl\Http\Request> request)
    {

    }

    public function match(string uri, string method = "GET") -> object|boolean
    {

    }
}
