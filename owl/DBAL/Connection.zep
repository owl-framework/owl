
namespace Owl\DBAL;

use Owl\Event\Manager as EventsManager;

class Connection
{
	/**
	 * Current used driver
	 *
	 * @var Driver\DriverInterface
	 */
	protected driver {
		get
	};

	/**
	 * Current used db platform (MySQL|PgSQL)
	 *
	 * @var Platform\PlatformInterface
	 */
	protected platform {
		get
	};

	/**
	 * Construct connection
	 */
	public function __construct(var parameters, <EventsManager> eventsManager = null)
	{
		if (null === eventsManager) {
			let eventsManager = new EventsManager();
		}

		/**
		 * Current step no support for inst drivers
		 */
		if (isset(parameters["driver"])) {
			let this->driver = parameters["driver"];

			/**
			 * @todo Move to static
			 */
			let this->platform = this->driver->getNewPlatform();
		} else {
			throw new Exception("Driver not found in $parameters");
		}

		this->driver->setEventsManager(eventsManager);
	}

	/**
	 * Insert a row in the table with the specified data and types
	 * returns the number of affected rows
	 */
	public function insert(string! table, array! data, array! types = []) -> int
	{
		var query, stmt, value, set = [], columnName, fields;

		let fields = array_keys(data);

		for columnName, value in data {
			if (isset(types[columnName])) {
				if (types[columnName] == Driver\Pdo::PARAM_EXPRESSION) {
					let set[] = value;
					unset data[columnName];
				} else {
					let set[] = ":" . columnName . "";
				}
			} else {
				let set[] = ":" . columnName . "";
			}
		}

		let query = "INSERT INTO " . this->platform->wrap(table) . " (" . implode(",", fields) . ")  VALUES (" . implode(",", set) . ")";
		let stmt = this->driver->prepare(query);
		return stmt->execute(data);
	}

	/**
	 * Update row(s) of table and returns the number of updated rows
	 */
	public function update(string! table, array! data, array! identifiers, array! types = []) -> int
	{
		string query;

		var set = [], stmt, columnName;

		for columnName in data->keys() {
			let set[] = this->platform->wrap(columnName) . " = ?";
		}

		let query =  "UPDATE " . this->platform->wrap(table) . " SET " . implode(", ", set);

		var cnt;
		let cnt = count(identifiers);

		if (cnt > 0) {
			let query .= " WHERE ";

			if (cnt == 1) {
				let query .= this->platform->wrap(key(identifiers)) . " = ?";
			} else {
				throw new Exception("It's not implemented");
			}
		}

		let stmt = this->driver->prepare(query);

		return stmt->execute(array_merge(array_values(data), array_values(identifiers)));
	}

	/**
	 * Delete rows where $column = $key in $table
	 * return the number of affected rows
	 */
	public function deleteByColumn(string! table, string! column, var value, string! type = null)
	{
		/**
		 * @todo implement work with type
		 */
		return this->driver->execute("DELETE FROM " . this->platform->wrap(table) . " WHERE " . column . " = " . value);
	}

	/**
	 * Delete rows from tables where identifiers are specified
	 * return the number of affected rows
	 */
	public function delete(string! table, array! identifiers, array! types = []) -> int
	{
		var query, key, value;
		boolean first = true;

		let query = "DELETE FROM " . this->platform->wrap(table) . " WHERE ";

		for key, value in identifiers {
			if (!first) {
				let query .= " AND";
			} else {
				let first = false;
			}

			let query = " " . key . " = " . value;
		}

		/**
		 * @todo implement work with type
		 */
		return this->driver->execute(query);
	}

	/**
	 * Prepares a statement for execution and returns a statement
	 */
	public function prepare(var statement)
	{
		var smt;
		let smt = this->driver->prepare(statement);
		return smt;
	}
}
