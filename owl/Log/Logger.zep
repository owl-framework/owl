
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
     */
    protected records = [] {
        get
    };

    /**
     * Records limit to commit them to writers
     */
    protected recordsInterval = 1000 {
        get
    };

    /**
     * Log writers
     */
    protected writers = [] {
        get
    };

    public function __construct(writers = null)
    {
        var writer;

        for writer in writers {
            let this->writers[] = this->factoryWriter(writer);
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

        var writer, writerClass;

        if !isset(writerDescription["class"]) {
            throw new InvalidWriterException("Writer options 'class' is not exists");
        }

        if !class_exists(writerDescription["class"]) {
            throw new InvalidWriterException("Writer class is not exists");
        }

        let writerClass = writerDescription["class"];
        let writer = new {writerClass}();

        if isset( writerDescription["levels"] ) {
            writer->setLevels( writerDescription["levels"] );
        }

        if isset( writerDescription["options"] ) {
            writer->setOptions( writerDescription["options"] );
        }

        if isset( writerDescription["formatter"] ) {
            writer->setFormatter( writerDescription["formatter"] );
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
    public function log(var level, string message, array context = [])
    {
        let this->records[] = new Record(level, microtime(true), message, context);

        if (count(this->records) >= this->recordsInterval) {
            this->commit();
        }
    }
}
