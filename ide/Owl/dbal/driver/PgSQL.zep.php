<?php

namespace Owl\DBAL\Driver;


class PgSQL extends \Owl\DBAL\Driver\AbstractPdo implements \Owl\DBAL\Driver\DriverInterface
{

    /**
     * @return \Owl\DBAL\Platform\PlatformInterface 
     */
    public function getNewPlatform() {}

}
