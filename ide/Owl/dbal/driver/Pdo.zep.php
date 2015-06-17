<?php

namespace Owl\DBAL\Driver;


class Pdo extends \PDO
{

    const PARAM_EXPRESSION = 10;


    /**
     * @param string $dsn 
     * @param mixed $username 
     * @param mixed $password 
     * @param array $options 
     */
    public function __construct($dsn, $username = null, $password = null, $options = null) {}

}
