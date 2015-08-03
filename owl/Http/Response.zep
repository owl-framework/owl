
namespace Owl\Http;

use Owl\Std\ArrayBag;

class Response implements ResponseInterface
{
	const STATUS_CODE_OK = 200;

	/**
	 * @var int
	 */
	protected code = Response::STATUS_CODE_OK {
		get, set
	};

	/**
	 * @var string
	 */
	protected content = "" {
		get, set, toString
	};

	/**
	 * @var \Owl\Std\ArrayBag
	 */
	protected headers {
		get
	};

	public function __construct()
	{
		let this->headers = new HeadersBag([]);
	}

	public function send() -> boolean
	{
		http_response_code(this->code);

		echo (string) this->content;

		return true;
	}

	/**
	 * Check whether status is OK
	 */
	public function isOk() -> boolean
	{
		return this->code == 200;
	}

	/**
	 * Check whether status is Server Error
	 */
	public function isServerError() -> boolean
	{
		return this->code >= 500 && this->code < 600;
	}
}
