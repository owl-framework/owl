<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests;

use Owl\DBAL;
use Owl\Event\Manager;

class Utils
{
    public static function getConnection()
    {
        $eventsManager = new Manager();

        switch ($GLOBALS['db_type']) {
            case 'mysql':
            case 'pdo_mysql':
                $driver = new DBAL\Driver\MySQL('mysql:host='.$GLOBALS['db_host'].';charset=utf8;dbname='.$GLOBALS['db_name'].';port=' . $GLOBALS['db_port'], $GLOBALS['db_username'], $GLOBALS['db_password'], array());
                break;
//            case 'pgsql':
//            case 'pdo_pgsql':
//                $driver = new DBAL\Driver\PgSQL('pgsql:host=localhost;dbname='.$GLOBALS['db_name'], $GLOBALS['db_username'], $GLOBALS['db_password'], array());
//                break;
            default:
                throw new \InvalidArgumentException('Unsupported db type : ' . $GLOBALS['db_type']);
                break;
        }

        $connection = new DBAL\Connection(['driver' => $driver], $eventsManager);
        return $connection;
    }
}
