
namespace Owl\Http;

interface RequestInterface
{
    public function getUri() -> string|null;

    public fn getPost(string! key, var defaultValue = null) -> string;

    public fn getServer(string! key, var defaultValue = null) -> string;

    public fn getScheme() -> string;
}