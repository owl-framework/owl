
namespace Owl\DBAL\Driver;

use PdoStatement;
use Owl\DBAL\Platform\PlatformInterface;

class PgSQL extends AbstractPdo implements DriverInterface
{
	public function getNewPlatform() -> <PlatformInterface>
	{
		return new \Owl\DBAL\Platform\PgSQL();
	}
}
