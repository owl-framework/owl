<?php

namespace Owl\DBAL\Platform;

interface PlatformInterface
{

    /**
     * @param string $id 
     */
    public function wrap($id);

}
