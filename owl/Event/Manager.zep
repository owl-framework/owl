
namespace Owl\Event;

class Manager
{
	protected listeners = [];

	public fn listen(var eventName, callable! callback)
	{
		let this->listeners[eventName][] = callback;
	}

	public function emit(string eventName, var data = null)
	{
		var events, callback;

		if fetch events, this->listeners[eventName] {
			for callback in events {
				if typeof callback == "array" {
					call_user_func_array(callback, [new Event(eventName, data)]);
				} else {
					/**
					 * It's a hack, to call by zval
					 */
					{callback}(new Event(eventName, data));
				}
			}
		}
	}
}
