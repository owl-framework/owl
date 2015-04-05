
namespace Owl\Router\Http;

class DynamicRoute extends \Owl\Router\Route
{
    protected pattern;

    protected uriParameters;

    public function __construct(string uri)
    {
        let this->uri = uri;
    }

    public fn getPattern()
    {
        if (this->pattern) {
            return this->pattern;
        }

        var pattern;
        let pattern = this->uri;

        var str;
        let str = this->uri;

        var len;
        let len = strlen(str);

        var parts = [], part, params;

        if (len > 3) {
            if (substr(str, 0, 1) === "/") {
                let parts = explode("/", str);

                unset(parts[0]);
            }
        }

        for _, part in parts {
            let params = explode(":", part);

            switch (count(params)) {
                case 2:
                    if (empty(params[0])) {
                        let str = str_replace(part, "(?P<" . params[1] . ">[0-9]++)", str);
                    } elseif (params[1] == "int") {
                        let str = str_replace(part, "(?P<" . params[0] . ">[0-9]++)", str);
                    } elseif (substr(params[1], 0, 1) == '{' && $params[1][strlen($params[1]) - 1] == '}') {
                        let str = substr(params[1], 1, -1);

                        let str = str_replace(part, str, str);
                    }
                    break;
                case 1:
                    break;
            }
        }

        let this->pattern = ("`^" . str . "$`u");
        return this->pattern;
    }

    public function match(string uri) -> boolean|array
    {
        array parameters = [];

        if (!preg_match(this->getPattern(), uri, parameters)) {
            return false;
        }

        unset(parameters[0]);

        // rly?
        unset(parameters[count(parameters) - 1]);

        let this->uriParameters = parameters;
        return parameters;
    }
}