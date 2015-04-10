
namespace Owl\Std;

class ArrayBag
{
    protected elements;

    public function __construct(array! input)
    {
        let this->elements = input;
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
