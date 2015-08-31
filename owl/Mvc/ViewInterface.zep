
namespace Owl\Mvc;

use Owl\Exception;

interface ViewInterface
{
	public function getPath() -> string;

	/**
	 * Render view
	 */
	public function render(string! path, array parameters = null) -> string|boolean;
}
