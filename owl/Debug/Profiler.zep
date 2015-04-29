
namespace Owl\Debug;

use Owl\ApplicationInterface;
use Owl\DispatcherInterface;
use Owl\Http\ResponseInterface;

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

	public function setContent(<ResponseInterface> response) -> <ResponseInterface>
	{
	    var html, resp;

		let resp = new \Owl\Http\Response();

	    let html = "<html><head>";

	    let html .= "<link href=\"//owl-framework.github.io/assets/profiler/min.css\" media=\"all\" rel=\"stylesheet\">";

		let html .= "</head><body>";

	    let html .= "<div id='owl-debug-bar'>";
			let html .= sprintf("%.4F ms", microtime(true) - this->startTime);
			let html .= "\t";
			let html .= sprintf("%.3f MB", memory_get_peak_usage() / 1024 / 1024);
			let html .= "\t";
			let html .= "HTTP Code " . response->getCode();
  	    let html .= "</div>";


		let html .= "<pre><code>";
				let html .= json_encode(json_decode(response->getContent()), JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE);
		let html .= "</code></pre>";

		let html .= "</body></html>";

        resp->setContent(html);

        return resp;
	}
}
