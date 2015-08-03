PHP_ARG_ENABLE(owl, whether to enable owl, [ --enable-owl   Enable Owl])

if test "$PHP_OWL" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, OWL_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_OWL, 1, [Whether you have Owl])
	owl_sources="owl.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c owl/cache/driver.zep.c
	owl/cache/driver/cachedriver.zep.c
	owl/log/writerinterface.zep.c
	owl/log/abstractwriter.zep.c
	owl/log/loggerinterface.zep.c
	owl/dbal/driver/driverinterface.zep.c
	owl/dbal/platform/platforminterface.zep.c
	owl/exception.zep.c
	owl/http/responseinterface.zep.c
	owl/log/formatterinterface.zep.c
	owl/router/route.zep.c
	owl/applicationinterface.zep.c
	owl/dispatcherinterface.zep.c
	owl/http/requestinterface.zep.c
	owl/http/response.zep.c
	owl/log/abstractlogger.zep.c
	owl/mvc/controller.zep.c
	owl/router/routerinterface.zep.c
	owl/std/arraybag.zep.c
	owl/std/collection/abstractcollection.zep.c
	owl/annotations/annotation.zep.c
	owl/annotations/classannotationsresult.zep.c
	owl/annotations/exception.zep.c
	owl/annotations/reader.zep.c
	owl/application.zep.c
	owl/bridge/lynx/rest/entitycontroller.zep.c
	owl/cache/driver/memcache.zep.c
	owl/cache/driver/memcached.zep.c
	owl/cache/driver/nativearray.zep.c
	owl/cache/driver/redis.zep.c
	owl/console/application.zep.c
	owl/console/commandinterface.zep.c
	owl/dbal/connection.zep.c
	owl/dbal/driver/mysql.zep.c
	owl/dbal/driver/pdo.zep.c
	owl/dbal/driver/pgsql.zep.c
	owl/dbal/exception.zep.c
	owl/dbal/platform/mysql.zep.c
	owl/dbal/platform/pgsql.zep.c
	owl/debug/memoryprofiler.zep.c
	owl/debug/profiler.zep.c
	owl/event/event.zep.c
	owl/event/manager.zep.c
	owl/http/headersbag.zep.c
	owl/http/request.zep.c
	owl/http/response/json.zep.c
	owl/log/exception/invalidformatterexception.zep.c
	owl/log/exception/invalidwriterexception.zep.c
	owl/log/formatter/json.zep.c
	owl/log/formatter/line.zep.c
	owl/log/logger.zep.c
	owl/log/record.zep.c
	owl/log/writer/devnull.zep.c
	owl/log/writer/echobrowser.zep.c
	owl/log/writer/file.zep.c
	owl/module/manager.zep.c
	owl/mvc/view.zep.c
	owl/mvc/view/engine/php.zep.c
	owl/router/http/dynamicroute.zep.c
	owl/router/http/staticroute.zep.c
	owl/router/router.zep.c
	owl/service/manager.zep.c
	owl/session/managerinterface.zep.c
	owl/std/collection/arraycollection.zep.c owl/annotations/scanner.c
	owl/annotations/parser.c"
	PHP_NEW_EXTENSION(owl, $owl_sources, $ext_shared,, )
	PHP_SUBST(OWL_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([owl], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([owl], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/owl], [php_OWL.h])

fi
