
namespace Owl\Log;

abstract class AbstractLogger implements LoggerInterface
{
	/**
	 * Log levers constants
	 */
	const LEVEL_ALERT     = 0x01;
	const LEVEL_CRITICAL  = 0x02;
	const LEVEL_EMERGENCY = 0x03;
	const LEVEL_ERROR     = 0x04;
	const LEVEL_INFO      = 0x05;
	const LEVEL_DEBUG     = 0x06;
	const LEVEL_NOTICE    = 0x07;
	const LEVEL_WARNING   = 0x08;

	/**
	 * Get level title by internal level code
	 */
	public static function getLevelTitle(var level) -> string
	{
		switch level {
			case self::LEVEL_ALERT:
				return "alert";

			case self::LEVEL_CRITICAL:
				return "critical";

			case self::LEVEL_EMERGENCY:
				return "emergency";

			case self::LEVEL_ERROR:
				return "error";

			case self::LEVEL_INFO:
				return "info";

			case self::LEVEL_DEBUG:
				return "debug";

			case self::LEVEL_NOTICE:
				return "notice";

			case self::LEVEL_WARNING:
				return "warning";
		}

		return "unknown";
	}

	/**
	 * @inheritdoc
	 */
	public function emergency(string message, array context = [])
	{
		this->log(self::LEVEL_EMERGENCY, message, context);
	}

	/**
	 * @inheritdoc
	 */
	public function alert(string message, array context = [])
	{
		this->log(self::LEVEL_ALERT, message, context);
	}

	/**
	 * @inheritdoc
	 */
	public function critical(string message, array context = [])
	{
		this->log(self::LEVEL_CRITICAL, message, context);
	}

	/**
	 * @inheritdoc
	 */
	public function error(string message, array context = [])
	{
		this->log(self::LEVEL_ERROR, message, context);
	}

	/**
	 * @inheritdoc
	 */
	public function warning(string message, array context = [])
	{
		this->log(self::LEVEL_WARNING, message, context);
	}

	/**
	 * @inheritdoc
	 */
	public function notice(string message, array context = [])
	{
		this->log(self::LEVEL_NOTICE, message, context);
	}

	/**
	 * @inheritdoc
	 */
	public function info(string message, array context = [])
	{
		this->log(self::LEVEL_INFO, message, context);
	}

	/**
	 * @inheritdoc
	 */
	public function debug(string message, array context = [])
	{
		this->log(self::LEVEL_DEBUG, message, context);
	}

	/**
	 * @inheritdoc
	 */
	abstract public function log(var level, string message, array context = []);
}
