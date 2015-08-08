
namespace Owl\Http;

class Response implements ResponseInterface
{
	const STATUS_CODE_OK = 200;

	/**
	 * @var int
	 */
	protected statusCode = Response::STATUS_CODE_OK {
		get, set
	};

	/**
	 * @var string
	 */
	protected content = "" {
		get, set, toString
	};

	/**
	 * @var \Owl\Http\HeadersBag
	 */
	protected headers {
		get
	};

	/**
	 * @var boolean
	 */
	protected sent = false;

	public function __construct()
	{
		let this->headers = new HeadersBag([]);
	}

	/**
	 * Check if the response is already sent
	 */
	public function isSent() -> boolean
	{
		return this->sent;
	}

	public function send() -> boolean
	{
		http_response_code(this->statusCode);

		this->headers->send();
		echo (string) this->content;

		let this->sent = true;

		return true;
	}

	/**
	 * Check whether status is OK
	 */
	public function isOk() -> boolean
	{
		return this->statusCode == 200;
	}

	/**
	 * Check whether status is Server Error
	 */
	public function isServerError() -> boolean
	{
		return this->statusCode >= 500 && this->statusCode < 600;
	}
}
