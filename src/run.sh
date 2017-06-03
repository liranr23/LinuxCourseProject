#!/bin/bash

#Copying config to the usr share folder,
sudo cp ./movies.conf /usr/share/nginx/movies.conf

sudo nginx -c movies.conf &>/dev/null

pid=$( cat ./moviesProcess.pid )
if [ "$pid" != "" ];then
    kill -KILL "$pid"
fi
spawn-fcgi -p 8000 fcgi -P moviesProcess.pid

