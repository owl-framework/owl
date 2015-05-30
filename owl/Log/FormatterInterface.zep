
namespace Owl\Log;

interface FormatterInterface
{
	/**
	 * Format record
	 */
	public function format(<Record> record) -> string;
}
