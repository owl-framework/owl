
namespace Owl\Filter;

interface FilterInterface
{
	/**
	 * Returns the result of filtering $value
	 */
    public function filter(var value) -> var;
}
