
namespace Owl\Event;

class Manager
{
    protected listeners = [];

    public fn listen(var eventName, callable callback)
    {
        let this->listeners[eventName][] = callback;
    }

    public function emit(string eventName, var data = null)
    {
        var events, callback;

        if fetch events, this->listeners[eventName] {
            for callback in events {
                {callback}(data);
            }
        }
    }
}