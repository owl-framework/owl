
namespace Owl\Http;

use Owl\Std\ArrayBag;

class Response implements ResponseInterface
{
    const STATUS_CODE_OK = 200;

    protected code = Response::STATUS_CODE_OK {get, set};

    protected content {get, set};

    protected headers {get};

    public function __construct()
    {
        let this->headers = new ArrayBag([]);
    }

    public function send() -> boolean
    {
        http_response_code(this->code);

        echo this->content;

        return true;
    }
}
