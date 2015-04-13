/**
 * @author Patsura Dmitry http://github.com/ovr <talk@dmtry.me>
 */

namespace Owl\Cache\Driver;

class Redis extends CacheDriver
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

    public fn setInstance(<\Redis> instance)
    {
        let this->instance = instance;
    }

    /**
     * @return \Redis
     */
    public fn getInstance()
    {
        if (is_null($this->instance)) {
            let this->instance = new \Redis();
            this->instance->connect("localhost");

            this->instance->setOption(\Redis::OPT_SERIALIZER, \Redis::SERIALIZER_PHP);

            return this->instance;
        }

        return $this->instance;
    }

    public fn __destruct()
    {
        if (this->instance) {
            this->instance->close();
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
        return this->getInstance()->flushDB();
    }
}
