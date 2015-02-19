
namespace Owl;

class Application
{
    protected request {get};

    protected response {get};

    protected di {get};

    public function __construct(var di = null)
    {
        let this->di = di;
    }

    public function bootstrap()
    {

    }

    public function handle(<Http\Request> request, <Http\Response> response = null) -> <Http\Response>
    {
        var matchedRoute, router;

        let router = this->di->get("router");
        let matchedRoute = router->match(request);

        var_dump(matchedRoute);

        if (is_null(response)) {
            let response = new Http\Response();
        }

        return response;
    }
}
