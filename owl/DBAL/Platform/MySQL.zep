
namespace Owl\DBAL\Platform;

class MySQL
{
    inline public function wrap(id)
    {
        return "`" . id . "`";
    }
}
