AM_CXXFLAGS = -std=c++11

bin_PROGRAMS = fcgi

fcgi_SOURCES = fcgi.cpp Database.cpp Location.cpp Movie.cpp Order.cpp

fcgi_LDADD = -lfcgi -lfcgi++ -lsqlite3 -lRequestManager

fcgi_LDFLAGS = -Wl,-rpath -Wl,/usr/local/lib

lib_LTLIBRARIES = libRequestManager.la

libRequestManager_la_SOURCES = RequestManager.cpp  

libRequestManager_la_LIBADD = -lsqlite3

