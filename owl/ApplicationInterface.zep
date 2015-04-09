
namespace Owl;

interface ApplicationInterface
{
    const ENV_PRODUCTION = "production";

    public fn __construct(<Manager> di = null, <Event\Manager> eventManager = null, string env = self::ENV_PRODUCTION);

    /**
     * Handle Http Request
     */
    public fn handle(<RequestInterface> request, <Response> response = null) -> <Response>;
}
