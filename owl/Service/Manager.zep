
namespace Owl\Service;

use Owl\Exception;

class Manager
{
	protected instances = [];

	protected services = [];

	public fn setService(string! name, var definition)
	{
		if (is_object(definition) || is_callable(definition, true)) {
			let this->instances[name] = definition;
		} else {
			let this->services[name] = definition;
		}
	}

	public fn get(string! name)
	{
		return this->getInstance(name);
	}

	public fn has(string! name) -> boolean
	{
		return isset(this->instances[name]) || isset(this->services[name]);
	}

	public fn getInstance(string! name) -> var
	{
		var instance;

		if fetch instance, this->instances[name] {
			return instance;
		}

		throw new Exception("Instance wasn't found by name: " . name);
	}

	public fn getService(string! name) -> var
	{
		var service;

		if fetch service, this->services[name] {
			return service;
		}

		throw new Exception("Service wasn't found by name: " . name);
	}
}
