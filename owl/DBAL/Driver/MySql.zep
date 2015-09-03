
namespace Owl\DBAL\Driver;

use PdoStatement;
use Owl\DBAL\Platform\PlatformInterface;

class MySQL extends AbstractPdo implements DriverInterface
{
	public function getNewPlatform() -> <PlatformInterface>
	{
		return new \Owl\DBAL\Platform\MySQL();
	}
}
