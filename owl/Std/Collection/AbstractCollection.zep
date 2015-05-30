
namespace Owl\Std\Collection;

use Countable;
use IteratorAggregate;

abstract class AbstractCollection implements Countable, IteratorAggregate
{
	/**
	 * Get elements count from a collection
	 */
	abstract public function count();

	/**
	 * Get iterator
	 */
	abstract public function getIterator();

	/**
	 * Execute a function on each element in the collection
	 */
	abstract public function map(<\Closure> func);

	/**
	 * Execute a function on each element in the collection and
	 * removes the element from the collection if the executed function returns false
	 */
	abstract public function filter(func);

	/**
	 * Set the current element to the first element and returns it
	 */
	abstract public function first();

	/**
	 * Set current element to the last element and returns it
	 */
	abstract public function last();

	/**
	 * Add a element to the collection
	 */
	abstract public function add(var element);
}
