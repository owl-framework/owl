<?php

namespace Owl\DBAL\Driver;

interface DriverInterface
{

    /**
     * @return bool 
     */
    public function isConnected();

    /**
     * @return \Owl\DBAL\Platform\PlatformInterface 
     */
    public function getNewPlatform();


    public function lastInsertId();

    /**
     * @param mixed $statement 
     * @return \PdoStatement 
     */
    public function prepare($statement);

}
