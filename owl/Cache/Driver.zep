
namespace Owl\Cache;

interface Driver
{
    /**
     * To initialize cache provider
     *
     * @return mixed
     */
    public fn getInstance();

    /**
     * Save data
     *
     * @param $id
     * @param $data
     * @param int $lifeTime
     * @return boolean
     */
    public fn save(string! id, var data, int! lifeTime = 3600);

    /**
     * Save data by id
     *
     * @param $id
     * @return boolean
     */
    public fn delete(string! id);

    /**
     * Fetch data by id
     *
     * @param $id
     * @return mixed
     */
    public fn get(string! id);

    /**
     * Is value exist?
     *
     * @param $id
     * @return boolean
     */
    public fn exists(string! id);

    /**
     * Flush all values
     *
     * @return boolean
     */
    public fn flush();
}
