
namespace Owl\Filter;

class Trim extends AbstractFilter
{
    public fn filter(var value) -> var
    {
		return trim(value);
    }
}
