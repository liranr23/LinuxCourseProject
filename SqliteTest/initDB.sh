#!/bin/bash

gcc -o initDB initDB.c  -l sqlite3

./initDB
