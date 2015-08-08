
namespace Owl\Filter;

class StripTags extends AbstractFilter
{
    public fn filter(var value) -> var
    {
		return strip_tags(value);
    }
}
