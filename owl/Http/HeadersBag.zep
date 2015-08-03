
namespace Owl\Http;

use Owl\Std\ArrayBag;

class HeadersBag extends ArrayBag
{
	public fn send()
	{
		var header, value;

		for header, value in this->elements {
			if !empty value {
				header(header . ": " . value, true);
			} else {
				header(header, true);
			}
		}
	}
}
