AC_INIT([Linux Project], 1.0)
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR(src)
LT_PREREQ([2.4.6])
AC_CHECK_LIB([fcgi], [main], 
  [HAVE_FCGI=1] [TEST_LIBS="$TEST_LIBS -lfcgi"], 
  AC_MSG_WARN([fcgi is not installed.]))
AC_CHECK_LIB([fcgi++], [main], 
  [HAVE_FCGIPP=1] [TEST_LIBS="$TEST_LIBS -lfcgi++"], 
  AC_MSG_WARN([fcgi++ is not installed.]))
AC_CHECK_LIB([sqlite3], [main], 
  [HAVE_sqlite3=1] [TEST_LIBS="$TEST_LIBS -lsqlite3"], 
  AC_MSG_WARN([sqlite3 is not installed.]))
LT_INIT
AC_PROG_CXX
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
