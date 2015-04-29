<?php
/**
 * @author Ivanov Sergey <xufocoder@gmail.com>
 */

use Owl\Log\Record;
use Owl\Log\Writer\EchoBrowser;

/**
 * Class WriterBrowserTest
 */
class WriterBrowserTest extends \PHPUnit_Framework_TestCase {

    public function testWriterBrowserPush() {

        $record = new Record( 1, 2, 3 );

        $records = [
            $record
        ];

        $writer = new EchoBrowser();
        $writer->commit( $records );

        ob_start();
        $writer->push();
        $buffer = ob_get_contents();
        ob_end_clean();

        $formatted_record = $writer->getFormatter()->format($record);

        $this->assertTrue( $buffer == $formatted_record );

    }

    public function testWriterBrowserDestruct() {

        $record = new Record( 1, 2, 3 );

        $records = [
            $record
        ];

        $writer = new EchoBrowser();
        $writer->commit($records);

        $formatted_record = $writer->getFormatter()->format($record);

        ob_start();
        unset($writer);
        $buffer = ob_get_contents();
        ob_end_clean();

        $this->assertTrue( $buffer == $formatted_record );

    }

}