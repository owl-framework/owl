
namespace Owl\Router\Http;

class DynamicRoute extends \Owl\Router\Route
{
    protected pattern;

    public fn getPattern()
    {
        if (this->pattern) {
            return this->pattern;
        }

        var pattern;
        let pattern = this->uri;

        let this->pattern = ("`^" . pattern . "$`u");

        return this->pattern;
    }

    public function match(string uri)
    {
        return this->uri == uri;
    }
}