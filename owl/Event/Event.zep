
namespace Owl\Event;

class Event
{
	protected name {get};

	protected data {get};

	public function __construct(name, data)
	{
		let this->name = name;
	}
}
