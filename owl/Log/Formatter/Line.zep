
namespace Owl\Log\Formatter;

use Owl\Log\Logger;
use Owl\Log\AbstractFormatter;

class Line extends AbstractFormatter
{
    public function format(var type, float timestamp, string message, array context = []) -> string
    {
        let message = this->interpolate(message, context);

        return Logger::getLevelTitle(type).":" . date(DATE_RFC2822, timestamp) . ":". message;
    }
}