
namespace Owl\Router;

interface RouterInterface
{
     public function match(string uri, string method = "GET") -> object|boolean;
}
