
namespace Owl\Cache\Driver;

class NativeArray extends CacheDriver
{
    protected options;

    /**
     * @var array|null
     */
    protected instance;

    public fn __construct(array options = null)
    {
        let this->options = options;
    }

    public fn setInstance(array instance)
    {
        let this->instance = instance;
    }

    /**
     * @return array
     */
    public fn getInstance()
    {
        if (is_null($this->instance)) {
            let this->instance = [];
            return this->instance;
        }

        return this->instance;
    }

    public fn __destruct()
    {
        if (this->instance) {
            unset(this->instance);
        }
    }

    /**
     * {@inheritDoc}
     */
    public fn save(var id, var data, var lifetime = 3600)
    {
        let this->instance[id] = data;

        return true;
    }

    /**
     * {@inheritDoc}
     */
    public fn delete(id)
    {
        unset(this->instance[id]);
    }

    /**
     * {@inheritDoc}
     */
    public fn get(string! id)
    {
        var value;

        if fetch value, this->instance[id] {
            return value;
        }

        return false;
    }

    /**
     * {@inheritDoc}
     */
    public fn flush()
    {
        let this->instance = [];
    }
}
