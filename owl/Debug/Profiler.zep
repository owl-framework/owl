
namespace Owl\Debug;

use Owl\ApplicationInterface;
use Owl\Event\Manager as EventManager;

class Profiler {
	protected startTime;

	public function __construct()
	{
		let this->startTime = microtime(true);
	}

	public function logEvent(var event)
	{
		printf(" %.4F сек.", (microtime(true) - this->startTime));
	}

	public function listen(<EventManager> em)
	{
		em->listen(ApplicationInterface::EVENT_BEFORE_HANDLE, [this, "logEvent"]);
		em->listen(ApplicationInterface::EVENT_AFTER_HANDLE, [this, "logEvent"]);
	}
}
