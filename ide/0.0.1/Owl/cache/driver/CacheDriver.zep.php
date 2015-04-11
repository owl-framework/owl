<?php

namespace Owl\Cache\Driver;

abstract class CacheDriver implements \Owl\Cache\Driver
{

    /**
     * @param string $id 
     */
	public function exists($id) {}

}
