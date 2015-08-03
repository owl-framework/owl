
namespace Owl\Http\Response;

use Owl\Http\Response;
use Owl\Http\HeadersBag;

class Json extends Response
{
    public function __construct()
    {
        let this->headers = new HeadersBag([
            "Content-Type": "application/json"
        ]);
    }

    public function setContent(var content)
    {
        let this->content = json_encode(content);
    }
}
