
namespace Owl\Log\Formatter;

use Owl\Log\Logger;
use Owl\Log\Record;
use Owl\Log\FormatterInterface;

class Json implements FormatterInterface
{
    /**
      * @inheritdoc
      */
    public function format(<Record> record) -> string
    {
        return json_encode([
            "type": Logger::getLevelTitle(record->level),
            "message": record->message,
            "timestamp": record->timestamp
        ]);
    }
}