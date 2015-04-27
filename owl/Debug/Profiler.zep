
namespace Owl\Debug;

use Owl\ApplicationInterface;
use Owl\DispatcherInterface;

use Owl\Event\Manager as EventManager;
use Owl\Event\Event;

class Profiler {
	protected startTime;

	protected lastTime;

	public function __construct()
	{
		var time;
		let time = microtime(true);

		let this->startTime = time;
		let this->lastTime = time;
	}

	public function logEvent(<Event> event)
	{
		//printf(event->getName() . " %.4F сек. </br>", (microtime(true) - this->lastTime));

		let this->lastTime = microtime(true);
	}

	public function listen(<EventManager> em)
	{
		em->listen(ApplicationInterface::EVENT_BEFORE_HANDLE, [this, "logEvent"]);
		em->listen(ApplicationInterface::EVENT_AFTER_HANDLE, [this, "logEvent"]);

		//em->listen(DispatcherInterface::EVENT_ROUTER_BEFORE_EXECUTE, [this, "logEvent"]);
		em->listen(DispatcherInterface::EVENT_ROUTER_AFTER_EXECUTE, [this, "logEvent"]);

		em->listen(DispatcherInterface::EVENT_AFTER_ACTION, [this, "logEvent"]);
		//em->listen(DispatcherInterface::EVENT_AFTER_INIT, [this, "logEvent"]);
	}

	public function show()
	{
	    var html;

	    let html = "<style>";
	    	let html .= "#owl-debug-bar {width: 100%;height: 40px;line-height: 40px;border-bottom: 1px solid black;margin-bottom: 20px;background-color: #f8f8f8;}";
	    	let html .= "body {margin: 0; padding: 0;}";
	    let html .= "</style>";

	    let html .= "<div id='owl-debug-bar'>";
			let html .= sprintf("%.4F ms", microtime(true) - this->startTime);
  	    let html .= "</div>";

        echo html;
	}
}
