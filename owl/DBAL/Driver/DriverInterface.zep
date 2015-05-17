
namespace Owl\DBAL\Driver;

use PdoStatement;
use Owl\DBAL\Platform\PlatformInterface;

interface DriverInterface
{
	public function isConnected() -> boolean;

	public function getNewPlatform() -> <PlatformInterface>;

	public function lastInsertId();

	public function prepare(var statement) -> <PdoStatement>;
}
