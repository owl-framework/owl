
namespace Owl\Di;

class ServiceDefinition implements ServiceDefinitionInterface
{
	/**
	 * @var string
	 */
	protected name {
		get
	};

	/**
	 * @var object|callable
	 */
	protected definition {
		get
	};

	/**
	 * @var boolean
	 */
	protected shared = false {
		get
	};

	/**
	 * @var boolean
	 */
	protected resolved = false {
		get
	};

	/**
	 * Phalcon\Di\Service
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 */
	public final function __construct(string! name, definition, boolean shared = false)
	{
		let this->name = name,
			this->definition = definition,
			this->shared = shared;
	}
}
