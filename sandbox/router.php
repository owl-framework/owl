<?php
/**
 * @author Patsura Dmitry https://github.com/ovr <talk@dmtry.me>
 */

$string = "/user/id:{[0-9]++}/";

function preparePattern($string)
{
    $len = strlen($string);

    if ($len > 3) {
        if ($string[0] === '/' && $string[$len - 1] == '/') {
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

            if ($params[1][0] == '{' && $params[1][strlen($params[1]) - 1] == '}') {
                $str = substr($params[1], 1, -1);

                $string = str_replace($part, $str, $string);
            }
        }
    }

    return $string;
}

var_dump(preparePattern('/user/id:{[0-9]++}/'));

$match = preg_match('`^' . preparePattern('/user/id:{([0-9]++)}/') . '$`u', "/user/1/", $params);

var_dump($match);
var_dump($params);