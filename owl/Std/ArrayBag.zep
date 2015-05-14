
namespace Owl\Std;

class ArrayBag implements \Countable
{
	protected elements;

	public function __construct(array! input)
	{
		let this->elements = input;
	}

	public function count()
	{
		return count(this->elements);
	}

	public function get(string! key, var defaultValue = null)
	{
		var value;

		if fetch value, this->elements[key] {
			return value;
		}

		return defaultValue;
	}
}
