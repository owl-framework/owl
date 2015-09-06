
namespace Owl\Http;

use Owl\Std\ArrayBag;

class Request implements RequestInterface
{
    const GET      = "GET";
    const POST     = "POST";
    const PUT      = "PUT";
    const DELETE   = "DELETE";

    const OPTIONS  = "OPTIONS";
    const HEAD     = "HEAD";
    const TRACE    = "TRACE";
    const CONNECT  = "CONNECT";
    const PATCH    = "PATCH";
    const PROPFIND = "PROPFIND";

	/**
	 * @var string
	 */
    protected method = self::GET {
    	get
	};

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected get;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected post;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected server;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected headers;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected files;

    /**
     * @var \Owl\Std\ArrayBag
     */
    protected cookies;

    /**
     * Get request URI
     */
    inline public function getUri() -> string
    {
        return this->server->get("REQUEST_URI", "/");
    }

    /**
     * Get request path (URI without GET parameters)
     */
    public function getPath() -> string
    {
        return parse_url(this->getUri(), PHP_URL_PATH);
    }

    public fn getParam(string! key, var defaultValue = null)
    {
        return this->get->get(key, defaultValue);
    }

    public fn getPost(string! key, var defaultValue = null) -> var|boolean
    {
        return this->post->get(key, defaultValue);
    }

    public fn getServer(string! key, var defaultValue = null) -> var|boolean
    {
        return this->server->get(key, defaultValue);
    }

	public fn getScheme() -> string
	{
		var https;

		let https = this->getServer("HTTPS");
		if https {
			if https == "off" {
				return "http";
			} else {
				return "https";
			}
		}

		return "http";
	}

    public fn __construct(var get, var post, var server, var headers, var files, var cookies)
    {
        let this->get = new ArrayBag(get);
        let this->post = new ArrayBag(post);
        let this->server = new ArrayBag(server);
        let this->headers = new ArrayBag(headers);
        let this->files = new ArrayBag(files);
        let this->cookies = new ArrayBag(cookies);

		let this->method = this->server->get("REQUEST_METHOD", self::GET);
    }

    public static fn createFromGlobals() -> <Request>
    {
        return new Request(_GET, _POST, _SERVER, [], _FILES, _COOKIE);
    }
}
