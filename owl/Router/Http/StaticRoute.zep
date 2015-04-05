
namespace Owl\Router\Http;

class StaticRoute extends \Owl\Router\Route
{
    public function __construct(string uri)
    {
        let this->uri = uri;
    }

    public function match(string uri)
    {
        return this->uri == uri;
    }
}