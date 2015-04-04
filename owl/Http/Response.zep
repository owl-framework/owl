
namespace Owl\Http;

class Response implements ResponseInterface
{
    const STATUS_CODE_OK = 200;

    protected code = Response::STATUS_CODE_OK {get, set};

    protected content {get, set};

    public function send() -> boolean
    {
        echo this->content;

        return true;
    }
}
