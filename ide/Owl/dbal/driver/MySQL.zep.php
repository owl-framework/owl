<?php

namespace Owl\DBAL\Driver;

class MySQL
{

    protected $eventsManager;


    protected $dsn;


    protected $username;


    protected $password;


    protected $driverOptions;


    protected $connection;


    /**
     * @param mixed $eventsManager 
     */
    public function setEventsManager($eventsManager) {}


    public function getEventsManager() {}

    /**
     * @param string $dsn 
     * @param mixed $username 
     * @param mixed $password 
     * @param array $driverOptions 
     */
    public function __construct($dsn, $username = null, $password = null, $driverOptions = array()) {}

    /**
     * @return bool 
     */
    public function isConnected() {}

    /**
     * Execute query and return result
     *
     * @param string $query 
     * @return int 
     */
    public function execute($query) {}


    public function connect() {}

    /**
     * @return \Owl\DBAL\Platform\PlatformInterface 
     */
    public function getNewPlatform() {}


    public function lastInsertId() {}

    /**
     * @param mixed $statement 
     * @return \PdoStatement 
     */
    public function prepare($statement) {}

}
