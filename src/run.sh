#!/bin/bash

#Copying config to the usr share folder,
sudo cp ./movies.conf /usr/share/nginx/movies.conf

sudo nginx -c movies.conf 2> /dev/null

pid=$( pgrep -x "fcgi" )

if [ "$pid" != "" ] ;then
    kill -KILL "$pid"
fi
spawn-fcgi -p 8000 fcgi

