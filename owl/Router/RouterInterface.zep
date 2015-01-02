
namespace Owl\Router;

use Owl\Http\Request;

interface RouterInterface
{
     public function match(string uri, string method = Request::GET) -> object|boolean;
}
