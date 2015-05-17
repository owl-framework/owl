
namespace Owl\DBAL\Platform;

class MySQL implements PlatformInterface
{
    inline public function wrap(string id)
    {
        return "`" . id . "`";
    }
}
