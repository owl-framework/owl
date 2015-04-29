
namespace Owl\Log\Formatter;

use Owl\Log\Logger;
use Owl\Log\Record;
use Owl\Log\FormatterInterface;

class Line implements FormatterInterface
{
    /**
      * @inheritdoc
      */
    public function format(<Record> record) -> string
    {
        return Logger::getLevelTitle(record->level).":" . date(DATE_RFC2822, record->timestamp) . ":". record->message;
    }
}