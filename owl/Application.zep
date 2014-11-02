
namespace Owl;

class Application
{
    protected request {get};

    protected response {get};

    public function bootstrap()
    {

    }

    public function handle(<Http\Request> request, <Http\Response> response = null) -> <Http\Response>
    {
        if (is_null(response)) {
            let response = new Http\Response();
        }

        return response;
    }
}
