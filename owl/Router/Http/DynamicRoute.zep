
namespace Owl\Router\Http;

class DynamicRoute extends \Owl\Router\Route
{
    protected pattern;

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
        let len = strlen(this->uri);

        var parts = [], part, params;

        if (len > 3) {
            if (substr(str, 0, 1) === "/" && substr(str, (len - 1), 1) == "/") {
                let parts = explode("/", str);

                unset($parts[0]);
                unset($parts[count($parts)]);
            }
        }

        for _, part in parts {
            let params = explode(":", part);

            if (count(params) == 2) {
                if (empty(params[0])) {
                    let str = str_replace(part, "(?P<" . params[1] . ">[0-9]++)", str);
                } elseif (params[1] == "int") {
                    let str = str_replace(part, "(?P<" . params[0] . ">[0-9]++)", str);
                } elseif (substr(params[1], 0, 1) == '{' && $params[1][strlen($params[1]) - 1] == '}') {
                    let str = substr(params[1], 1, -1);

                    let str = str_replace(part, str, str);
                }
            } elseif (count(params) == 1) {

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

        let this->parameters = array_merge(this->parameters, parameters);
        return this->parameters;
    }
}