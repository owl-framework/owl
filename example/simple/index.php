<?php
/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

use Owl\Application;
use Owl\Http\Request;

$application = new Application();
$response = $application->handle(new Request());

var_dump($response