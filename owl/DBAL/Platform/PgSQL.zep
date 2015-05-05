
namespace Owl\DBAL\Platform;

class PgSQL
{
    inline public function wrap(id)
    {
        return id;
    }
}
