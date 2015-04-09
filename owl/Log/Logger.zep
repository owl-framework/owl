
namespace Owl\Log;

class Logger implements LoggerInterface
{
    const EMERGENCY = "emergency";
    const ALERT     = "alert";
    const CRITICAL  = "critical";
    const ERROR     = "error";
    const WARNING   = "warning";
    const NOTICE    = "notice";
    const INFO      = "info";
    const DEBUG     = "debug";

    /**
     * System is unusable.
     */
    public function emergency(string message, array context = [])
    {
        return this->log(self::EMERGENCY, message, context);
    }

    /**
     * Action must be taken immediately.
     *
     * Example: Entire website down, database unavailable, etc. This should
     * trigger the SMS alerts and wake you up.
     */
    public function alert(string message, array context = [])
    {
        return this->log(self::ALERT, message, context);
    }

    /**
     * Critical conditions.
     *
     * Example: Application component unavailable, unexpected exception.
     */
    public function critical(string message, array context = [])
    {
        return this->log(self::CRITICAL, message, context);
    }

    /**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     */
    public function error(string message, array context = [])
    {
        return this->log(self::ERROR, message, context);
    }

    /**
     * Exceptional occurrences that are not errors.
     *
     * Example: Use of deprecated APIs, poor use of an API, undesirable things
     * that are not necessarily wrong.
     */
    public function warning(string message, array context = [])
    {
        return this->log(self::WARNING, message, context);
    }

    /**
     * Normal but significant events.
     */
    public function notice(string message, array context = [])
    {
        return this->log(self::NOTICE, message, context);
    }

    /**
     * Interesting events.
     *
     * Example: User logs in, SQL logs.
     */
    public function info(string message, array context = [])
    {
        return this->log(self::INFO, message, context);
    }

    /**
     * Detailed debug information.
     */
    public function debug(string message, array context = [])
    {
        return this->log(self::DEBUG, message, context);
    }

    /**
     * Logs with an arbitrary level.
     */
    public function log(var level, string message, array context = [])
    {
        echo "[" . level . "]" . " " . message;
    }
}
