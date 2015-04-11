
namespace Owl\Http\Response;

use Owl\Http\Response;
use Owl\Std\ArrayBag;

class Json extends Response
{
    public function __construct()
    {
        let this->headers = new ArrayBag([
            "Content-Type": "application/json"
        ]);
    }

    public function setContent(var content)
    {
        let this->content = json_encode(content);
    }
}
