
namespace Owl\Log;

interface FormatterInterface {
    /**
     * Format record
     */
    public function format(var level, float timestamp, string message, array context = []) -> string;
}