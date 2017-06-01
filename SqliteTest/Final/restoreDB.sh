#!/bin/bash

rm database.db
gcc -o initDB initDB.c  -l sqlite3
./initDB
