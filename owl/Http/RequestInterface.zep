
namespace Owl\Http;

interface RequestInterface
{
	/**
	 * Get Request's URI
	 */
    public function getUri() -> string;

    /**
     * Get Request's path (URI without GET parameters)
     */
    public function getPath() -> string;

	public fn getParam(string! key, var defaultValue = null);

    public fn getPost(string! key, var defaultValue = null);

    public fn getServer(string! key, var defaultValue = null);

    public fn getScheme() -> string;

	public fn getMethod() -> string;
}
