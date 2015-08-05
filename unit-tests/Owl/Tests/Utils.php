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

        switch (getenv('db_type')) {
            case 'mysql':
            case 'pdo_mysql':
                $driver = new DBAL\Driver\MySQL(
                    'mysql:host='.getenv('db_host').';charset=utf8;dbname='.getenv('db_name').';port=' . getenv('db_port'),
                    getenv('db_username'),
                    getenv('db_password'),
                    array()
                );
                break;
            case 'pgsql':
            case 'pdo_pgsql':
                $driver = new DBAL\Driver\PgSQL(
                    'pgsql:host='.getenv('db_host').';dbname='.getenv('db_name').';port=' . getenv('db_port'),
                    getenv('db_username'),
                    getenv('db_password'),
                    array()
                );
                break;
            default:
                throw new \InvalidArgumentException('Unsupported db type : ' . getenv('db_type'));
                break;
        }

        $connection = new DBAL\Connection(['driver' => $driver], $eventsManager);
        return $connection;
    }
}
