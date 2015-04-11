<?php

namespace Owl\Cache;

interface Driver
{

    /**
     * To initialize cache provider
     *
     * @return mixed 
     */
	public function getInstance();

    /**
     * Save data
     *
     * @param string $id 
     * @param mixed $data 
     * @param int $lifeTime 
     * @param $data  
     * @param int $$lifeTime 
     * @return boolean 
     */
	public function save($id, $data, $lifeTime = 3600);

    /**
     * Save data by id
     *
     * @param string $id 
     * @param $id  
     * @return boolean 
     */
	public function delete($id);

    /**
     * Fetch data by id
     *
     * @param string $id 
     * @param $id  
     * @return mixed 
     */
	public function get($id);

    /**
     * Is value exist?
     *
     * @param string $id 
     * @param $id  
     * @return boolean 
     */
	public function exists($id);

    /**
     * Flush all values
     *
     * @return boolean 
     */
	public function flush();

}
