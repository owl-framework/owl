
namespace Owl\Log;

class Record
{
	/**
	 * Record level
	 */
	public level;

	/**
	 * Record timestamp
	 */
	public timestamp;

	/**
	 * Record message
	 */
	public message;

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
	 * Create and interpolate record message
	 */
	public function __construct(var level, float timestamp, string message, array context = [])
	{
		let message = this->interpolate(message, context);

		let this->level = level;
		let this->timestamp = timestamp;
		let this->message = message;
	}
}
