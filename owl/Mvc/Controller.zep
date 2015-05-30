
namespace Owl\Mvc;

use Owl\Http\Request;
use Owl\Http\Response;
use Owl\Service\Manager;

class Controller
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
	 * @var \Owl\Service\Manager
	 */
	protected di {
		get
	};

	public function __construct(<Request> request, <Response> response, <Manager> di)
	{
		let this->request = request;
		let this->response = response;
		let this->di = di;
	}
}
