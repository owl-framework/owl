
namespace Owl\Debug;

use Owl\ApplicationInterface;
use Owl\DispatcherInterface;
use Owl\Http\ResponseInterface;

use Owl\Event\Manager as EventManager;
use Owl\Event\Event;

class Profiler
{
	protected startTime;

	protected lastTime;

	protected assetsUri = "//owl-framework.github.io/assets/profiler/min.css" {
		get, set
	};

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
		var html, resp, tmp;

		let resp = new \Owl\Http\Response();

		let html = "<html><head>";

		let html .= "<link href=\"" . this->assetsUri . "\" media=\"all\" rel=\"stylesheet\">";

		let html .= "</head><body>";

		let html .= "<div id='owl-debug-bar'>";
		let html .= "<span class=\"label color-2\">" . sprintf("%.4Fms", microtime(true) - this->startTime) . "</span>";
		let html .= "<span class=\"label color-3\">" . sprintf("%.3fMB", memory_get_peak_usage() / 1024 / 1024)  . "</span>";

		if (response->getStatusCode() == 200) {
			let tmp = "2";
		} elseif (response->getStatusCode() == 500) {
			let tmp = "1";
		} else {
			let tmp = "3";
		}

		let html .= "<span class=\"label color-" . tmp . "\">" . response->getStatusCode() . "</span>";
		let html .= "</div>";

		if (response instanceof \Owl\Http\Response\Json) {
			let html .= "<pre><code>";
				let html .= json_encode(json_decode(response->getContent()), JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE);
			let html .= "</code></pre>";
		} else {
			let html .= response->getContent();
		}

		let html .= "</body></html>";

		resp->setContent(html);

		return resp;
	}
}
