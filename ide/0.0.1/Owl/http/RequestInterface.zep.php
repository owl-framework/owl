<?php

namespace Owl\Http;

interface RequestInterface
{

    /**
     * @param string $key 
     * @return string 
     */
	public function getPost($key);

    /**
     * @param string $key 
     * @return string 
     */
	public function getServer($key);

    /**
     * @return string 
     */
	public function getScheme();

}
