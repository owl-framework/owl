
namespace Owl\Http;

interface ResponseInterface
{
	public function send() -> boolean;

	public function getContent() -> string;

	public function setCode(int code);

	public function getCode() -> int;
}
