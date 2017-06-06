#!/bin/bash

#Setting root of server to dist
dist=$(pwd)
dist="${dist%/*}"/distLocal
sed -i "/<root>/c\root $dist ;" movies.conf

#Copying config to the usr share folder,
sudo cp ./movies.conf /usr/share/nginx/movies.conf

sudo nginx -c movies.conf 2> /dev/null

pid=$( pgrep "fcgi" )

if [ "$pid" != "" ] ;then
    sudo kill -KILL "$pid"
fi
sudo spawn-fcgi -p 8000 fcgi

