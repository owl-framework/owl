
namespace Owl\Http;

class Response implements ResponseInterface
{
    const STATUS_CODE_OK = 200;

    protected code = Response::STATUS_CODE_OK {get, set};

    protected content {get, set};

    public function send() -> boolean
    {
        http_response_code(this->code);

        echo this->content;
        
        return true;
    }
}
