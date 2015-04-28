
namespace Owl\Log;

/**
 * Logger usage:
 *
 * $Logger = new Logger([
 *     [
 *         'class' => '\Owl\Log\Writer\File',
 *         'levels' => ['error', 'warning'],
 *         'formatter' => '\Owl\Log\Formatter\Syslog',
 *         'options' => [
 *             'logFile' => APP_ROOT '/logs/my.log'
 *         ]
 *     ],
 *     [
 *         'class' => '\Owl\Log\Writer\Email',
 *         'levels' => ['alert'],
 *         'formatter' => '\Owl\Log\Formatter\Line',
 *         'options' => [
 *             'from'  => 'robot@localhost',
 *             'to' => 'support@localhost',
 *             'subject' => 'System Alert log'
 *         ]
 *     ],
 * ]);
 */
class Logger extends AbstractLogger implements LoggerInterface
{

    /**
     * Logs with an arbitrary level.
     */
    public function log(var level, string message, array context = [])
    {

    }
}
