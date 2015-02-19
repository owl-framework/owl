
namespace Owl;

class Application
{
    protected request {get};

    protected response {get};

    protected di {get};

    public fn __construct(var di = null)
    {
        let this->di = di;
    }

    /**
     * Handle Http Request
     */
    public fn handle(<Http\Request> request, <Http\Response> response = null) -> <Http\Response>
    {
        var matchedRoute, router;

        let router = this->di->get("router");
        let matchedRoute = router->matchRequest(request);

        if (is_null(response)) {
            let response = new Http\Response();
        }

        return response;
    }
}
