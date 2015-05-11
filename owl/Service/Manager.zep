
namespace Owl\Service;

use Owl\Exception;

class Manager
{
	protected instances = [];

	protected services = [];

	public fn setService(string! name, var service)
	{
		if (is_object(service)) {
			let this->instances[name] = service;
		} else {
			let this->services[name] = service;
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
