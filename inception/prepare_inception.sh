#!/bin/bash

touch srcs/.env
echo "DB_NAME=wordpress" >> srcs/.env
echo "DB_USER=dadoming" >> srcs/.env
echo "DB_ROOT_PASS=1234" >> srcs/.env
echo "DB_PASS=1234" >> srcs/.env
echo "DB_HOST=mariadb" >> srcs/.env
echo "DOMAIN=dadoming.42.fr" >> srcs/.env
echo "WP_ADMIN_USER=bossman" >> srcs/.env
echo "WP_ADMIN_PASS=bossman" >> srcs/.env
echo "WP_ADMIN_EMAIL=bossman@bossman" >> srcs/.env
echo "WP_USER=user" >> srcs/.env
echo "WP_USER_EMAIL=user"@user >> srcs/.env
echo "WP_USER_PASS=user" >> srcs/.env
