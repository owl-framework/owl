
namespace Owl\Di;

use Owl\Exception;

class Container implements ContainerInterface
{
	/**
	 * Service definitions
	 *
	 * @var array
	 */
	protected services = [];

	/**
	 * Service object instances
	 *
	 * @var array
	 */
	protected instances = [];

	public fn setService(string! name, var definition)
	{
		let this->services[name] = definition;
	}

	public fn set(string! name, var definition)
	{
		if (is_object(definition) || is_callable(definition, true)) {
			let this->instances[name] = definition;
		} else {
			this->setService(name, definition);
		}
	}

	public fn has(string! name) -> boolean
	{
		return isset(this->instances[name]) || isset(this->services[name]);
	}

	public fn get(string! name) -> object
	{
		var instance;

		if fetch instance, this->instances[name] {
			return instance;
		}

		throw new Exception("Instance wasn't found by name: " . name);
	}

	public fn getService(string! name) -> object
	{
		var service;

		if fetch service, this->services[name] {
			return service;
		}

		throw new Exception("Service wasn't found by name: " . name);
	}
}
