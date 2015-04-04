
namespace Owl\Http;

class Response
{
    const STATUS_CODE_OK = 200;

    protected code = Response::STATUS_CODE_OK {get, set};

    protected content {set};
}
