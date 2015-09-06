
namespace Owl\Http;

interface RequestInterface
{
    public function getUri() -> string|null;

    /**
     * Get request path (URI without GET parameters)
     */
    public function getPath() -> string;

	public fn getParam(string! key, var defaultValue = null);

    public fn getPost(string! key, var defaultValue = null);

    public fn getServer(string! key, var defaultValue = null);

    public fn getScheme() -> string;

	public fn getMethod() -> string;
}
