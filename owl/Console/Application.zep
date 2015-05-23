
namespace Owl\Console;

class Application
{
	protected commands {
		get
	};

	public function addCommand(<CommandInterface> command)
	{
		let this->commands[] = command;
	}

	public function addCommands(array! commands)
	{
		var command;

		for command in commands {
			this->addCommand(command);
		}
	}
}
