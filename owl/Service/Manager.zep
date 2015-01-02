
namespace Owl\Service;

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

    public fn getService(string! name) -> <mixed>
    {
        if (isset(this->services[name])) {
            return this->services[name];
        }

        throw new \Owl\Exception("No service was founded by name : " . name);
    }
}
