
namespace Owl\DBAL\Platform;

class PgSQL implements PlatformInterface
{
    inline public function wrap(string id)
    {
        return id;
    }
}
