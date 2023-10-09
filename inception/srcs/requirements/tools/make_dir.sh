#!/bin/bash
if [ ! -d "/home/${USER}/data" ]; then
        mkdir -p ~/data
        mkdir -p ~/data/mysql
        mkdir -p ~/data/wordpress
fi