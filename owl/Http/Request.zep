
namespace Owl\Http;

class Request
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

    public fn getParam()
    {

    }

    public fn getPost(string! key)
    {
        if isset _POST[key] {
            return _POST[key];
        }

        return false;
    }

    public fn getServer(string! key)
    {
        if isset _SERVER[key] {
            return _SERVER[key];
        }

        return false;
    }

    public fn getScheme()
    {
        /**
         * @todo implement it
         */
        return "http";
    }
}
