/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

namespace Owl\Cache\Driver;

class Memcached extends CacheDriver
{
    protected options;

    /**
     * @var \Memcache
     */
    protected instance;

    public fn __construct(array options = null)
    {
        let this->options = options;
    }

    public fn setInstance(<\Memcached> instance)
    {
        let this->instance = $instance;
    }

    /**
     * @return \Memcached
     */
    public fn getInstance()
    {
        if (is_null($this->instance)) {
            let this->instance = new \Memcached;
            this->instance->addServer("localhost", 11211);

            return this->instance;
        }

        return $this->instance;
    }

    public fn __destruct()
    {
        if (this->instance) {
            this->instance->resetServerList();
            unset(this->instance);
        }
    }

    /**
     * {@inheritDoc}
     */
    public fn save(var id, var data, var lifeTime = 3600)
    {
        return this->getInstance()->set(id, data, lifeTime);
    }

    /**
     * {@inheritDoc}
     */
    public fn delete(var id)
    {
        return this->getInstance()->delete($id);
    }

    /**
     * {@inheritDoc}
     */
    public fn get(var id)
    {
        return this->getInstance()->get(id);
    }

    /**
     * {@inheritDoc}
     */
    public fn flush()
    {
        return this->getInstance()->flush();
    }
}
