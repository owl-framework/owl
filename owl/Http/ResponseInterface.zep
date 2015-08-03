
namespace Owl\Http;

interface ResponseInterface
{
	public function send() -> boolean;

	public function getContent() -> string;

	public function setStatusCode(int code);

	public function getStatusCode() -> int;
}
