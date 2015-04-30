
namespace Owl\Log\Writer;

use Owl\Log\AbstractWriter;

/**
 * Special writer for testing
 */
class DevNull extends AbstractWriter
{
    /**
     * @inheritdoc
     */
    public function write(string record) { }
}