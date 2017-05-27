#!/bin/bash

#Copying config to the nginx folder, saving the last conf
sudo cp /etc/nginx/nginx.conf /etc/nginx/nginx.conf.bak && sudo rm /etc/nginx/nginx.conf
sudo cp ./nginx.conf /etc/nginx/

sudo nginx
g++ testcgi.cpp -lfcgi++ -lfcgi -o testcgi

spawn-fcgi -p 8000 -n testcgi
