
namespace Owl\Annotation;

class ClassAnnotationsResult
{
    protected annotations;

    protected methods;

    public function __construct(array! annotations, array! methods = null)
    {
        this->annotations = annotations;
        this->methods = methods;
    }
}