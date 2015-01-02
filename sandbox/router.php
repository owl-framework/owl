<?php
/**
 * @author Patsura Dmitry https://github.com/ovr <talk@dmtry.me>
 */

$string = "/user/id:{[0-9]++}/";
$len = strlen($string);

if ($len > 3) {
    if ($string[0] === '/' && $string[$len-1] == '/') {
        $parts = explode('/', $string);

        unset($parts[0]);
        unset($parts[count($parts)]);
    }
}

foreach ($parts as $key => $part) {
    $params = explode(':', $part);
    if (count($params) == 2) {
        if ($params[1] == 'int') {
            $string = str_replace($part, '([0-9]++)', $string);
        }

        if ($params[1][0] == '{' && $params[1][strlen($params[1])-1] == '}') {
            $str = substr($params[1], 1, -1);

            $string = str_replace($part, $str, $string);
        }
    }
}
var_dump($parts);

//$newPart = false;
//$part = '';

//for ($i = 0; $i < strlen($string); $i++) {
//    var_dump($newPart);
//    $ch = $string[$i];
//
//    if ($ch == '/') {
//        $newPart = !$newPart;
//
//        if ($newPart === false) {
//            var_dump($part);
//            $part = '';
//        }
//
//        continue;
//    }
//
//    if ($newPart) {
//        $part .= $ch;
//    }
//}

//$pattern = '/user/([0-9]++)/';

var_dump($string);
$pattern = $string;
$match = preg_match("`^{$pattern}$`u", "/user/1/", $params);

var_dump($match);
var_dump($params);