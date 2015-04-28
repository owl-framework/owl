<?php
/**
 * @author Ivanov Sergey <xufocoder@gmail.com>
 */

use Owl\Log\Writer\EchoBrowser;

/**
 * Class WriterBrowserTest
 */
class WriterBrowserTest extends \PHPUnit_Framework_TestCase {

    public function testWriterBrowserPush() {

        $record = [ 1, 2, 3 ];

        $records = [
            $record
        ];

        $writer = new EchoBrowser();
        $writer->commit( $records );

        ob_start();
        $writer->push();
        $buffer = ob_get_contents();
        ob_end_clean();

        $formatted_record = $writer->getFormatter()->format($record[0], $record[1], $record[2]);

        $this->assertTrue( $buffer == $formatted_record );

    }

    public function testWriterBrowserDesctruct() {

        $record = [ 1, 2, 3 ];

        $records = [
            $record
        ];

        $writer = new EchoBrowser();
        $writer->commit($records);

        $formatted_record = $writer->getFormatter()->format($record[0], $record[1], $record[2]);

        ob_start();
        unset($writer);
        $buffer = ob_get_contents();
        ob_end_clean();

        $this->assertTrue( $buffer == $formatted_record );

    }

}