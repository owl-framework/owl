
namespace Owl\Router;

use Owl\Http\Request;
use Owl\Http\RequestInterface;

interface RouterInterface
{
     public function matchRequest(<RequestInterface> request);

     public function match(string uri, string method = Request::GET) -> object|boolean;
}
