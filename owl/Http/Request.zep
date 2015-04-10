
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

    protected method = self::GET {get};

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

    public function getUri() -> string|null
    {
        return this->server->get("REQUEST_URI", "/");
    }

    public fn getParam(string! key) -> var|boolean
    {
        var tmp;

        if isset this->get[key] {
            let tmp = this->get[key];
        }

        if isset this->post[key] {
            let tmp = this->post[key];
        }

        return tmp;
    }

    public fn getPost(string! key) -> var|boolean
    {
        if isset this->post[key] {
            return this->post[key];
        }

        return false;
    }

    public fn getServer(string! key) -> var|boolean
    {
        if isset this->server[key] {
            return this->server[key];
        }

        return false;
    }

    public fn getScheme() -> string
    {
        /**
         * @todo implement it
         */
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
    }

    public static fn createFromGlobals() -> <Request>
    {
        return new Request(_GET, _POST, _SERVER, [], _FILES, _COOKIE);
    }
}
