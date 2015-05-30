
namespace Owl\Std\Collection;

use ArrayIterator;

class ArrayCollection extends AbstractCollection
{
	protected elements;

	/**
	 * {@inheritDoc}
	 */
	public function __construct(array! elements = [])
	{
		let this->elements = elements;
	}

	/**
	 * {@inheritDoc}
	 */
	public function add(var element)
	{
		let this->elements[] = element;
	}

	/**
	 * Checks is collection empty?
	 */
	public function isEmpty() -> boolean
	{
		return this->count() != 0;
	}

	/**
	 * {@inheritDoc}
	 */
	public function map(<\Closure> func)
	{
		let this->elements = array_map(func, this->elements);
	}

	/**
	 * {@inheritDoc}
	 */
	public function filter(func)
	{
		let this->elements = array_filter(this->elements, func);
	}

	/**
	 * {@inheritDoc}
	 */
	public function first()
	{
		return reset(this->elements);
	}

	/**
	 * {@inheritDoc}
	 */
	public function last()
	{
		return end(this->elements);
	}

	/**
	 * {@inheritDoc}
	 */
	public function getIterator() -> <ArrayIterator>
	{
		return new ArrayIterator(this->elements);
	}

	/**
	 * {@inheritDoc}
	 */
	public function count() -> int
	{
		return count(this->elements);
	}
}
