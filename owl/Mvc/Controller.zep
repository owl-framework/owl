
namespace Owl\Mvc;

use Owl\Http\Request;
use Owl\Http\Response;

class Controller
{
    /**
     * @var \Owl\Http\RequestInterface
     */
    protected request {get};

    public function __construct(<Request> request, <Response> response = null)
    {
        let this->request = request;
    }
}
