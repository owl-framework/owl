
namespace Owl\Http;

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

    protected get;

    protected post;

    protected server;

    protected headers;

    protected files;

    protected cookies;

    public function getUri() -> string|null
    {
        return isset(this->server["REQUEST_URI"]) ? this->server["REQUEST_URI"] : null;
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
        let this->get = get;
        let this->get = get;
        let this->server = server;
        let this->headers = headers;
        let this->files = files;
        let this->cookies = cookies;
    }

    public static fn createFromGlobals() -> <Request>
    {
        return new Request(_GET, _POST, _SERVER, [], _FILES, _COOKIE);
    }
}
