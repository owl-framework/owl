
namespace Owl\Log;

class AbstractFormatter implements FormatterInterface
{
    /**
     * Interpolates context values into the message placeholders.
     *
     * @see http://www.php-fig.org/psr/psr-3/
     */
    protected function interpolate(string message, array context = [])
    {
        var replace, key, value;

        if count(context) > 0 {
            let replace = [];
            for key, value in context {
                let replace["{" . key . "}"] = value;
            }
            return strtr(message, replace);
        }
        return message;
    }

    /**
     * @inheritdoc
     */
    public function format(var level, float timestamp, string message, array context = []) -> string;
}