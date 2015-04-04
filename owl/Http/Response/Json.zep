
namespace Owl\Http\Response;

use Owl\Http\Response;

class Json extends Response
{
    public function setContent(var content)
    {
        let this->content = json_encode(content);
    }
}
