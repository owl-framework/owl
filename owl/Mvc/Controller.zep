
namespace Owl\Mvc;

use Owl\Http\Request;
use Owl\Http\Response;
use Owl\Di\ContainerInterface;

class Controller implements ControllerInterface
{
	/**
	 * @var \Owl\Http\RequestInterface
	 */
	protected request {
		get
	};

	/**
	 * @var \Owl\Http\ResponseInterface
	 */
	protected response {
		get
	};

	/**
	 * @var \Owl\Di\ContainerInterface
	 */
	protected di {
		get
	};

	public function __construct(<Request> request, <Response> response, <ContainerInterface> di)
	{
		let this->request = request;
		let this->response = response;
		let this->di = di;
	}
}
