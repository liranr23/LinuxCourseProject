#!/bin/bash
g++ *.cpp -std=c++11 -I/usr/local/include -lfcgi -lfcgi++  -lsqlite3 -o fcgi 
