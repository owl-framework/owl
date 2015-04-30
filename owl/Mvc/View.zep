
namespace Owl\Mvc;

class View
{
	protected path = "./../resources/views/" {
		get, set
	};

	public function render(string! path, array parameters = null)
	{
		if !file_exists(this->path . path) {
			throw new \Exception("File is not exists");
		}

		ob_start();

		require this->path . path;

		var tmp;
		let tmp = ob_get_contents();

		ob_end_clean();

		return tmp;
	}
}
