
namespace Owl\Annotations;

class Parser
{
    public function parser(string comment)
    {
        return parse_annotations(comment, 1, 2);
    }
}