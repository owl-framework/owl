
namespace Owl\Http;

class Response implements ResponseInterface
{
    const STATUS_CODE_OK = 200;

    protected code = Response::STATUS_CODE_OK {get, set};

    protected content {get};

    public function setContent(var content)
    {
        let this->content = json_encode(content);
    }

    public function send() -> boolean
    {
        echo this->content;

        return true;
    }
}
