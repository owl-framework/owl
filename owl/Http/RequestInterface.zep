
namespace Owl\Http;

interface RequestInterface
{
    public fn getPost(string! key) -> string;
    
    public fn getServer(string! key) -> string;

    public fn getScheme() -> string;
}