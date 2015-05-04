
namespace Owl\Log\Writer;

use Owl\Log\AbstractWriter;

class EchoBrowser extends AbstractWriter
{
    /**
     * @inheritdoc
     */
    public function write(string record)
    {
        echo record;
    }
}
