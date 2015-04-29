
namespace Owl;

use Owl\Service\Manager;

use Owl\Http\Request;
use Owl\Http\RequestInterface;
use Owl\Http\Response;
use Owl\Http\ResponseInterface;

use Owl\Router\Http\StaticRoute;

class Application implements ApplicationInterface
{
	/**
	 * Latest Request
	 *
	 * @var \Owl\Http\RequestInterface
	 */
	protected request {
		get
	};

	/**
	 * @var \Owl\Service\Manager
	 */
	protected di {
		get
	};

	/**
	 * Current env, see ENV_* constants
	 *
	 * @var string
	 */
	protected env {get};

	/**
	 * Count for dispatches
	 */
	protected currentLoop = 0;

	/**
	 * @var \Owl\Event\Manager
	 */
	protected eventManager;

	/**
	 * Handle parameters for exception catch
	 *
	 * @var array
	 */
	protected exceptionHandlerParameters = [
		"module": "Api",
		"controller": "Index",
		"action": "exception"
	] {
		set, get
	};

	public function __construct(<Manager> di = null, <Event\Manager> eventManager = null, string env = ApplicationInterface::ENV_PRODUCTION)
	{
		let this->di = di;
		let this->env = env;

		if (is_null(eventManager)) {
			let this->eventManager = new Event\Manager();
		} else {
			let this->eventManager = eventManager;
		}
	}

	/**
	 * Dispatch the action
	 */
	inline protected fn dispatch(var parameters, var matchedRoute, var response)
	{
		var handlerClass, controller, result, action, e, module;

		let this->currentLoop++;

		let handlerClass = "\\RestApp" . "\\";

		if fetch module, parameters["module"] {
			let handlerClass .= module . "\\";
		}

		let handlerClass .= "Controller\\" . parameters["controller"] . "Controller";

		if (this->currentLoop > 3) {
			response->setContent("World was crashed");
			response->setCode(500);

			return false;
		}

		try {
			if (!class_exists(handlerClass)) {
				throw new Exception("Class handler: '" . handlerClass . "' is not exists");
			}

			let controller = new {handlerClass}(this->request, response, this->di);

			this->eventManager->emit(DispatcherInterface::EVENT_AFTER_INIT, this);

			let action = parameters["action"] . "Action";
			if (!method_exists(controller, action)) {
				throw new Exception("Action '" . action . "' is not exists on '" . handlerClass ."'");
			}

			if (matchedRoute instanceof StaticRoute) {
				let result = controller->{action}();
			} else {
				/**
				 * @todo It's not a performance, 7200 vs 8300 RPS, maybe only request parameters?
				 */
				let result = call_user_func_array([controller, action], matchedRoute->uriParameters);
			}

			this->eventManager->emit(DispatcherInterface::EVENT_AFTER_ACTION, this);

			response->setContent(result);
		} catch \Exception, e {
			response->setCode(500);
			var_dump(e);
			this->dispatch(this->exceptionHandlerParameters, matchedRoute, response);
		}
	}

	/**
	 * Handle Http Request
	 */
	public fn handle(<RequestInterface> request, <ResponseInterface> response = null) -> <ResponseInterface>
	{
		var matchedRoute, router;

		this->eventManager->emit(ApplicationInterface::EVENT_BEFORE_HANDLE, this);

		if (is_null(response)) {
			let response = new Response();
		}

		let this->currentLoop = 0;
		this->eventManager->emit(DispatcherInterface::EVENT_ROUTER_BEFORE_EXECUTE, this);

		let router = this->di->get("router");
		let matchedRoute = router->matchRequest(request);

		this->eventManager->emit(DispatcherInterface::EVENT_ROUTER_AFTER_EXECUTE, this);

		if (matchedRoute) {
			var parameters;
            let parameters = matchedRoute->parameters;

			let this->request = request;
			this->dispatch(parameters, matchedRoute, response);
		} else {
			response->setCode(404);
			this->dispatch(parameters, matchedRoute, response);
		}

		this->eventManager->emit(ApplicationInterface::EVENT_AFTER_HANDLE, this);

		return response;
	}
}
