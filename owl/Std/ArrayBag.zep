
namespace Owl\Std;

class ArrayBag implements \Countable
{
	protected elements;

	public function __construct(array! input)
	{
		let this->elements = input;
	}

	public function count() -> int
	{
		return count(this->elements);
	}

	public function set(string! key, var value) -> void
	{
		let this->elements[key] = value;
	}

	public function has(string! key) -> boolean
	{
		return isset this->elements[key];
	}

	public function get(string! key, var defaultValue = null) -> var
	{
		var value;

		if fetch value, this->elements[key] {
			return value;
		}

		return defaultValue;
	}

	public function toArray() -> array
	{
		return this->elements;
	}
}
