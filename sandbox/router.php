<?php
/**
 * @author Patsura Dmitry https://github.com/ovr <talk@dmtry.me>
 */

$string = "/user/id:{[0-9]++}/";

class Route
{
    const GET = 2;

    const POST = 4;

    const ALL = self::GET | self::POST;

    protected $uri;

    protected $method;

    protected $pattern;

    public function __construct($uri, $method = self::ALL)
    {
        $this->uri = $uri;
        $this->method = self::ALL;
    }

    public function compile()
    {
        $string = $this->uri;
        $len = strlen($this->uri);

        $parts = [];

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
                    $string = str_replace($part, '(?P<'.$params[1].'>[0-9]++)', $string);
                }

                if ($params[1][0] == '{' && $params[1][strlen($params[1]) - 1] == '}') {
                    $str = substr($params[1], 1, -1);

                    $string = str_replace($part, $str, $string);
                }
            }
        }

        return $this->pattern = $string;
    }
}


$route = new Route('/user/id:int/');

$match = preg_match('`^' . $route->compile() . '$`u', "/user/1/", $params);

var_dump($match);
var_dump($params);