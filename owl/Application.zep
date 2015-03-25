
namespace Owl;

use Owl\Service\Manager;
use Http\Request;
use Http\Response;

class Application
{
    protected request {get};

    protected response {get};

    protected di {get};

    public fn __construct(<Manager> di = null)
    {
        let this->di = di;
    }

    /**
     * Handle Http Request
     */
    public fn handle(<Request> request, <Response> response = null) -> <Response>
    {
        var matchedRoute, router;

        if (is_null(response)) {
            let response = new Response();
        }
        
        let router = this->di->get("router");
        let matchedRoute = router->matchRequest(request);

        var_dump(matchedRoute);

        return response;
    }
}
