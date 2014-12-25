PHP_ARG_ENABLE(owl, whether to enable owl, [ --enable-owl   Enable Owl])

if test "$PHP_OWL" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, OWL_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_OWL, 1, [Whether you have Owl])
	owl_sources="owl.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c owl/application.zep.c
	owl/exception.zep.c
	owl/http/request.zep.c
	owl/http/response.zep.c
	owl/module/manager.zep.c
	owl/mvc/controller.zep.c
	owl/router/route.zep.c
	owl/router/router.zep.c
	owl/router/routerinterface.zep.c
	owl/service/manager.zep.c "
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
