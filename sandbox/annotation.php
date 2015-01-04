<?php

include_once __DIR__ . '/../examples/rest-app/app/modules/api/controllers/UserController.php';

$refClass = new ReflectionClass('UserController');
$parse = \Owl\Annotations\Reader::parse($refClass->getDocComment());
var_dump($parse);

foreach ($parse as $expr) {

}


foreach ($refClass->getMethods() as $method) {
    $parse = \Owl\Annotations\Reader::parse($method->getDocComment());
    var_dump($parse);
}