
namespace Owl\Di;

interface ContainerInterface
{
	public fn setService(string! name, var definition) -> void;

	public fn set(string! name, var definition) -> void;

	public fn has(string! name) -> boolean;

	public fn get(string! name) -> object;

	public fn getService(string! name) -> object;
}
