
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

	/**
	 * Get parameter from $_GET
	 */
	public fn getParam(string! key, var defaultValue = null);

	/**
	 * Get parameter from $_POST
	 */
	public fn getPost(string! key, var defaultValue = null);

	/**
	 * Get parameter from $_SERVER
	 */
	public fn getServer(string! key, var defaultValue = null);

	/**
	 * Get Request's scheme (HTTP/HTTPS)
	 */
	public fn getScheme() -> string;

	/**
	 * Get Request's method (GET, POST, PUT, DELETE, OPTIONS, HEAD, TRACE, CONNECT, PATCH, PROPFIND)
	 */
	public fn getMethod() -> string;
}
