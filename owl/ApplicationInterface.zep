
namespace Owl;

use Owl\Di\ContainerInterface;

use Owl\Http\Request;
use Owl\Http\RequestInterface;
use Owl\Http\Response;
use Owl\Http\ResponseInterface;

use Owl\Router\Http\StaticRoute;

interface ApplicationInterface
{
	const ENV_PRODUCTION = "production";
	const ENV_DEVELOPMENT = "development";

	const EVENT_BEFORE_HANDLE = "app:beforeHandle";
	const EVENT_AFTER_HANDLE = "app:afterHandle";


	public fn __construct(<ContainerInterface> di = null, <Event\Manager> eventManager = null, string env = self::ENV_PRODUCTION);

	/**
	 * Handle Http Request
	 */
	public fn handle(<RequestInterface> request, <ResponseInterface> response = null) -> <ResponseInterface>;

	/**
	 * Sets the default namespace
	 */
	public function setDefaultNamespace(string namespaceName);
}
