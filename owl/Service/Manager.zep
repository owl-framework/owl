
namespace Owl\Service;

class Manager
{
    protected services = [];

    public fn setService(string! name, var service)
    {
        let this->services[name] = service;
    }

    public fn getService(string! name) -> <mixed>
    {
        if (isset(this->services[name])) {
            return this->services[name];
        }

        throw new \Owl\Exception("No service was founded by name : " . name);
    }
}
