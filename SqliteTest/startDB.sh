#!/bin/bash

gcc -o initDB initDB.c  -l sqlite3
gcc -o populateDB populateDB.c -l sqlite3
./initDB
./populateDB
