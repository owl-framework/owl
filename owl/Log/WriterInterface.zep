
namespace Owl\Log;

interface WriterInterface {

    /**
     * Set formatter for writer
     */
    public function setFormatter(var formatter);

    /**
     * Get formatter
     */
    public function getFormatter() -> <FormatterInterface>;

    /**
     * Set options for writer
     */
    public function setOptions(var options);

    /**
     * Get options for writer
     */
    public function getOptions() -> array;

    /**
     * Get option for writer
     */
    public function getOption(string option);

    /**
     * Set message levels for writer
     */
    public function setLevels(var levels);

    /**
     * Get message levels for writer
     */
    public function getLevels() -> array;

    /**
     * Commit pack of messages
     */
    public function commit(array records) -> boolean;

    /**
     * Push all messages
     */
    public function push() -> boolean;
}