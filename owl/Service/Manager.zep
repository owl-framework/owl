
namespace Owl\Service;

class Manager
{
    protected services = [];

    public fn setService(string! name, var service)
    {
        let this->services[name] = service;
    }

    public fn getService(string! name)
    {
        if (isset(this->services[name])) {
            return this->services[name];
        }
    }
}
