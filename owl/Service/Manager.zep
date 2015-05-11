
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

	public fn has(string! name)
	{
		return isset(this->instances[name]) && isset(this->services[name]);
	}

	public fn getInstance(string! name) -> var
	{
		if (isset(this->instances[name])) {
			return this->instances[name];
		}

		throw new Exception("No instance was founded by name : " . name);
	}

	public fn getService(string! name) -> var
	{
		if (isset(this->services[name])) {
			return this->services[name];
		}

		throw new Exception("No service was founded by name : " . name);
	}
}
