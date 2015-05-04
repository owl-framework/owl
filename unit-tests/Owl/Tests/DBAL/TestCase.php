<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Owl\Tests\DBAL;

use Owl\DBAl;

class TestCase extends \Owl\Tests\TestCase
{
    /**
    * @return string
    * @throws \Exception
    */
    public function getDriverName()
    {
        switch ($GLOBALS['db_type']) {
            case 'mysql':
            case 'pdo_mysql':
                return 'MySQL';
            break;

            case 'pgsql':
            case 'pdo_pgsql':
                return 'PgSQL';
            break;

            default:
                throw new \Exception('Unknown driver: ' . $GLOBALS['db_type']);
            break;
        }
    }
}
