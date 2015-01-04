
namespace Owl\Annotations;

class ClassAnnotationsResult
{
    protected annotations;

    protected methods;

    public function __construct(array! annotations, array! methods = null)
    {
        let this->annotations = annotations;
        let this->methods = methods;
    }
}