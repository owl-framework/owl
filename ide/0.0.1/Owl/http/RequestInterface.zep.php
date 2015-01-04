<?php

namespace Owl\Http;

interface RequestInterface
{

    /**
     * @return string|null 
     */
	public function getUri();

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
