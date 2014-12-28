
namespace Owl\Annotations;

class Reader
{
    static public function parse(string comment)
    {
        return parse_annotations(comment, 1, 2);
    }
}