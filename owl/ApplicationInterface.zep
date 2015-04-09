
namespace Owl;

use Owl\Service\Manager;

use Owl\Http\Request;
use Owl\Http\RequestInterface;
use Owl\Http\Response;

use Owl\Router\Http\StaticRoute;

interface ApplicationInterface
{
    const ENV_PRODUCTION = "production";
    const ENV_DEVELOPMENT = "development";

    public fn __construct(<Manager> di = null, <Event\Manager> eventManager = null, string env = self::ENV_PRODUCTION);

    /**
     * Handle Http Request
     */
    public fn handle(<RequestInterface> request, <Response> response = null) -> <Response>;
}
