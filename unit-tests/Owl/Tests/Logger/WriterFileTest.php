<?php
/**
 * @author Ivanov Sergey <xufocoder@gmail.com>
 */

use Owl\Log\Writer\File;

/**
 * Class WriterFileTest
 */
class WriterFileTest extends \PHPUnit_Framework_TestCase {

    public function testWriterFileWrite() {

        $record = [ 1, 2, 3 ];

        $records = [
            $record
        ];

        $logFile = __DIR__ . "/temp.log";

        $writer = new File();
        $writer->setOptions([
            'logFile' => $logFile
        ]);
        $writer->commit($records);
        $writer->push();

        $formatted_record = $writer->getFormatter()->format($record[0], $record[1], $record[2]);
        $written_record = trim(file_get_contents($logFile));

        unlink($logFile);
        $this->assertTrue( $written_record == $formatted_record );
    }

}