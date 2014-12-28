
namespace Owl\Annotations;

class Parser
{
    static public function parse(string comment)
    {
        return parse_annotations(comment, 1, 2);
    }
}