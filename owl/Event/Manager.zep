
namespace Owl\Event;

class Manager
{
    protected listeners = [];

    public fn listen(var eventName, callable callback)
    {
        let this->listeners[eventName][] = callback;
    }
}