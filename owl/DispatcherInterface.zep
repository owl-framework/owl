
namespace Owl;

interface DispatcherInterface
{
	const EVENT_ROUTER_BEFORE_EXECUTE = "dispatch:beforeExecuteRoute";
	const EVENT_ROUTER_AFTER_EXECUTE = "dispatch:afterExecuteRoute";

	const EVENT_AFTER_ACTION = "dispatch:afterAction";
	const EVENT_AFTER_INIT = "dispatch:afterInitialize";
}
