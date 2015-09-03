<?php

namespace Owl\DBAL\Driver;


class MySQL extends \Owl\DBAL\Driver\AbstractPdo implements \Owl\DBAL\Driver\DriverInterface
{

    /**
     * @return \Owl\DBAL\Platform\PlatformInterface 
     */
    public function getNewPlatform() {}

}
