#!/bin/bash


mkdir /usr/local/bin/moviesProject
cp LinuxEnvProject/src/fcgi /usr/local/bin/moviesProject
cp LinuxEnvProject/src/movies.conf /usr/local/bin/moviesProject
cp LinuxEnvProject/src/run.sh /usr/local/bin/moviesProject
cp -r LinuxEnvProject/VueMovies/dist /usr/local/bin/moviesProject
cp -r LinuxEnvProject/db /usr/local/bin/moviesProject
