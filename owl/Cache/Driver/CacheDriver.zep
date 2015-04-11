
namespace Owl\Cache\Driver;

use Owl\Cache\Driver;

abstract class CacheDriver implements Driver
{
    public function exists(string! id)
    {
        return this->get(id) !== false;
    }
}
