
namespace Owl\Log;

/**
 * Describes a logger instance
 *
 * @see https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-3-logger-interface.md
 */
interface LoggerInterface
{
	/**
	 * System is unusable.
	 */
	public function emergency(string message, array context = []);

	/**
	 * Action must be taken immediately.
	 *
	 * Example: Entire website down, database unavailable, etc. This should
	 * trigger the SMS alerts and wake you up.
	 */
	public function alert(string message, array context = []);

	/**
	 * Critical conditions.
	 *
	 * Example: Application component unavailable, unexpected exception.
	 */
	public function critical(string message, array context = []);

	/**
	 * Runtime errors that do not require immediate action but should typically
	 * be logged and monitored.
	 */
	public function error(string message, array context = []);

	/**
	 * Exceptional occurrences that are not errors.
	 *
	 * Example: Use of deprecated APIs, poor use of an API, undesirable things
	 * that are not necessarily wrong.
	 */
	public function warning(string message, array context = []);

	/**
	 * Normal but significant events.
	 */
	public function notice(string message, array context = []);

	/**
	 * Interesting events.
	 *
	 * Example: User logs in, SQL logs.
	 */
	public function info(string message, array context = []);

	/**
	 * Detailed debug information.
	 */
	public function debug(string message, array context = []);

	/**
	 * Logs with an arbitrary level.
	 */
	public function log(var level, string message, array context = []);
}
