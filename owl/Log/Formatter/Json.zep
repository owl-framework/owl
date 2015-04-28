
namespace Owl\Log\Formatter;

use Owl\Log\Logger;
use Owl\Log\AbstractFormatter;

class Json extends AbstractFormatter
{
    public function format(var type, float timestamp, string message, array context = []) -> string
    {
        let message = this->interpolate(message, context);

        return json_encode([
            "type": Logger::getLevelTitle(type),
            "message": message,
            "timestamp": timestamp
        ]);
    }
}