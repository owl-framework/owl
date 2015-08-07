
namespace Owl\Mvc;

use Owl\Http\Request;
use Owl\Http\Response;
use Owl\Di\ContainerInterface;

interface ControllerInterface
{
	public function __construct(<Request> request, <Response> response, <ContainerInterface> di);
}
