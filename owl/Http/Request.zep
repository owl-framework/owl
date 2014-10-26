
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

    protected method {get};

    public fn getParam()
    {

    }

    public fn getPost(string! key)
    {

    }

    public fn getServer()
    {

    }

    public fn getScheme()
    {

    }
}
