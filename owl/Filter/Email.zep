
namespace Owl\Filter;

class Email extends AbstractFilter
{
    public fn filter(var value) -> var
    {
		return filter_var(value, FILTER_SANITIZE_EMAIL);
    }
}
