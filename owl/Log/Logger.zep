
namespace Owl\Log;

use Owl\Log\WriterInterface;
use Owl\Log\Exception\InvalidWriterException;

/**
 * Logger usage:
 *
 * $Logger = new Logger([
 *     [
 *         'class' => '\Owl\Log\Writer\File',
 *         'levels' => [Logger::LEVEL_ERROR, Logger::LEVEL_WARNING],
 *         'formatter' => '\Owl\Log\Formatter\Syslog',
 *         'options' => [
 *             'logFile' => APP_ROOT '/logs/my.log'
 *         ]
 *     ],
 *     [
 *         'class' => '\Owl\Log\Writer\Email',
 *         'levels' => [Logger::LEVEL_ALERT],
 *         'formatter' => '\Owl\Log\Formatter\Line',
 *         'options' => [
 *             'from'  => 'robot@localhost',
 *             'to' => 'support@localhost',
 *             'subject' => 'System Alert log'
 *         ]
 *     ],
 * ]);
 */
class Logger extends AbstractLogger implements LoggerInterface
{
	/**
	 * Array of <Record> elements
	 *
	 * @var \Owl\Log\Record[]
	 */
	protected records = [] {
		get
	};

	/**
	 * Records limit to commit them to writers
	 *
	 * @var int
	 */
	protected recordsInterval = 1000 {
		get, set
	};

	/**
	 * Log writers
	 *
	 * @var \Owl\Log\WriterInterface[]
	 */
	protected writers = [] {
		get
	};

	public function __construct(array writers = [])
	{
		var writerName, writerDescription;

		for writerName, writerDescription in writers {
			let this->writers[writerName] = this->factoryWriter(writerDescription);
		}
	}

	public function __destruct()
	{
		if (count(this->records) > 0 ) {
			this->commit();
		}
	}

	/**
	 * Create writer
	 */
	protected function factoryWriter(array writerDescription = []) -> <WriterInterface> {

		var writer, writerClass, levels, options, formatter;

		if !fetch writerClass, writerDescription["class"] {
			throw new InvalidWriterException("Writer options 'class' is not exists");
		}

		if !class_exists(writerClass) {
			throw new InvalidWriterException("Writer class is not exists");
		}

		let writer = new {writerClass}();

		if fetch levels, writerDescription["levels"] {
			writer->setLevels(levels);
		}

		if fetch options, writerDescription["options"] {
			writer->setOptions(options);
		}

		if fetch formatter, writerDescription["formatter"] {
			writer->setFormatter(formatter);
		}

		return writer;
	}

	/**
	 * Get writer
	 */
	public function getWriter(string name) -> <WriterInterface> | boolean
	{
		if isset(this->writers[name]) {
			return this->writers[name];
		}

		return false;
	}

	/**
	 * Commit records
	 */
	public function commit()
	{
		var writer;

		for writer in this->writers {
			writer->commit(this->records);
		}

		let this->records = [];
	}

	/**
	 * @inheritdoc
	 */
	public function log(int! level, string message, array context = [])
	{
		let this->records[] = new Record(level, microtime(true), message, context);

		if (count(this->records) >= this->recordsInterval) {
			this->commit();
		}
	}
}
