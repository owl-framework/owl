
namespace Owl\Http;

use Owl\Std\ArrayBag;

class Response implements ResponseInterface
{
	const STATUS_CODE_OK = 200;

	/**
	 * @var int
	 */
	protected code = Response::STATUS_CODE_OK {get, set};

	/**
	 * @var string
	 */
	protected content = "" {
		get, set
	};

	/**
	 * @var \Owl\Std\ArrayBag
	 */
	protected headers {get};

	public function __construct()
	{
		let this->headers = new ArrayBag([]);
	}

	public function send() -> boolean
	{
		http_response_code(this->code);

		echo this->content;

		return true;
	}
}
