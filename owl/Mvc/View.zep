
namespace Owl\Mvc;

use Owl\Exception;

class View
{
	/**
	 * Base path for views
	 */
	protected path = "./../resources/views/" {
		get, set
	};

	/**
	 * Render view
	 */
	public function render(string! path, array parameters = null) -> string|boolean
	{
		if !file_exists(this->path . path) {
			throw new Exception("File is not exists");
		}

		if !is_readable(this->path . path) {
			throw new Exception("File is not readable");
		}

		ob_start();

		if !is_null(parameters) {
			extract(parameters, EXTR_OVERWRITE);
		}

		require this->path . path;

		var tmp;
		let tmp = ob_get_contents();

		ob_end_clean();

		return tmp;
	}
}
