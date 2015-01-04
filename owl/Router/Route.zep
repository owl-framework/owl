
namespace Owl\Router;

use Owl\Http\Request;

abstract class Route
{
    public uri;

    public method = Request::GET;

    public parameters;
}
