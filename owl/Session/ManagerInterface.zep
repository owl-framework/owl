
namespace Owl\Session;

interface ManagerInterface
{
    public fn start() -> boolean;

    public fn getId() -> string;

    public fn rememberMe(int! ttl);

    public fn forgetMe() -> void;
}