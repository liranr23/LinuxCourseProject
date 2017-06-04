#!/bin/bash
g++ *.cpp -std=c++11 -lfcgi -lfcgi++ -lsqlite3 -o fcgi 
