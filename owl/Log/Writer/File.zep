
namespace Owl\Log\Writer;

use Owl\Log\AbstractWriter;

class File extends AbstractWriter
{
    /**
     * @inheritdoc
     */
    public function write(string record){
        file_put_contents($this->getOption("logFile"), record . PHP_EOL, FILE_APPEND);
    }
}
