
namespace Owl\Debug;

class MemoryProfiler
{
	public fn getPlatformInfo()
	{
		array memoryInfo = [];
		int tmp = 0;

		%{
			tmp = sizeof(zend_class_entry);
		}%

		let memoryInfo["zend_class_entry"] = tmp;

		%{
			tmp = sizeof(zend_object);
		}%

		let memoryInfo["zend_object"] = tmp;

		%{
			tmp = sizeof(zval);
		}%

		let memoryInfo["zval"] = tmp;

		%{
			tmp = sizeof(zvalue_value);
		}%

		let memoryInfo["zvalue_value"] = tmp;

		return memoryInfo;
	}
}
