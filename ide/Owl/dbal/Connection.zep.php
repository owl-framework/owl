<?php

namespace Owl\DBAL;


class Connection
{
    /**
     * Current used driver
     *
     * @var \Owl\DBAL\Driver\DriverInterface
     */
    protected $driver;

    /**
     * Current used db platform (MySQL|PgSQL)
     *
     * @var \Owl\DBAL\Platform\PlatformInterface
     */
    protected $platform;


    /**
     * Current used driver
     *
     * @return \Owl\DBAL\Driver\DriverInterface 
     */
    public function getDriver() {}

    /**
     * Current used db platform (MySQL|PgSQL)
     *
     * @return \Owl\DBAL\Platform\PlatformInterface 
     */
    public function getPlatform() {}

    /**
     * Construct connection
     *
     * @param mixed $parameters 
     * @param mixed $eventsManager 
     */
    public function __construct($parameters, \Owl\Event\Manager $eventsManager = null) {}

    /**
     * Insert a row in the table with the specified data and types
     * returns the number of affected rows
     *
     * @param string $table 
     * @param array $data 
     * @param array $types 
     * @return int 
     */
    public function insert($table, $data, $types = array()) {}

    /**
     * Update row(s) of table and returns the number of updated rows
     *
     * @param string $table 
     * @param array $data 
     * @param array $identifiers 
     * @param array $types 
     * @return int 
     */
    public function update($table, $data, $identifiers, $types = array()) {}

    /**
     * Delete rows where $column = $key in $table
     * return the number of affected rows
     *
     * @param string $table 
     * @param string $column 
     * @param mixed $value 
     * @param string $type 
     */
    public function deleteByColumn($table, $column, $value, $type = null) {}

    /**
     * Delete rows from tables where identifiers are specified
     * return the number of affected rows
     *
     * @param string $table 
     * @param array $identifiers 
     * @param array $types 
     * @return int 
     */
    public function delete($table, $identifiers, $types = array()) {}

    /**
     * Prepares a statement for execution and returns a statement
     *
     * @param mixed $statement 
     */
    public function prepare($statement) {}

}
