
namespace Owl\DBAL\Driver;

use PdoStatement;
use Owl\DBAL\Platform\PlatformInterface;

abstract class AbstractPdo
{
	protected eventsManager {set, get};

	protected dsn;

	protected username;

	protected password;

	protected driverOptions;

	protected connection;

	public function __construct(string! dsn, var username = null, var password = null, array driverOptions = [])
	{
		let this->dsn = dsn;
		let this->username = username;
		let this->password = password;
		let this->driverOptions = driverOptions;
	}

	inline public function isConnected() -> boolean
	{
		return !is_null(this->connection);
	}

	/**
	 * Execute query and return result
	 */
	public function execute(string! query) -> int
	{
		this->connect();

		return this->connection->exec(query);
	}

	public function connect()
	{
		if (this->isConnected()) {
			return false;
		}

		let this->connection = new Pdo(
			this->dsn,
			this->username,
			this->password,
			this->driverOptions
		);
	}

	abstract public function getNewPlatform() -> <PlatformInterface>;

	public function lastInsertId()
	{
		this->connect();

		return this->connection->lastInsertId();
	}

	public function prepare(var statement) -> <PdoStatement>
	{
		this->connect();

		return this->connection->prepare(statement);
	}
}
