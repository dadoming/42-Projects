#!/bin/bash

# Replace placeholders with env variables in db_script.sql
sed -i "s/MARIADB_PASSWORD/$DB_PASS/g" /etc/mysql/conf.d/db_script.sql && \
sed -i "s/MARIADB_ROOT_PASSWORD/$DB_ROOT_PASS/g" /etc/mysql/conf.d/db_script.sql && \
sed -i "s/MARIADB_DATABASE/$DB_NAME/g" /etc/mysql/conf.d/db_script.sql && \
sed -i "s/MARIADB_USER/$DB_USER/g" /etc/mysql/conf.d/db_script.sql

# Start MariaDB service
service mysql start 2>/dev/null
sleep 1

# Execute db_script.sql
mariadb < /etc/mysql/conf.d/db_script.sql 2>/dev/null
sleep 1

# Delete default mysql.user record for 'root' and flush privileges
echo "DELETE FROM mysql.user WHERE User='root'; FLUSH PRIVILEGES;" | mariadb -u$DB_USER -p$DB_ROOT_PASS 2>/dev/null

sleep 1
kill -9 $(ps aux | grep mysql | awk '{ print $2}') 2>/dev/null
sleep 1
mysqld_safe --bind-address=0.0.0.0

##!/bin/bash
#
#if [ ! -d "/var/lib/mysql/mysql" ]; then
#    chown -R mysql:mysql /var/lib/mysql
#
#    # Initialize the database
#    mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm
#
#    tfile=$(mktemp)
#    if [ ! -f "$tfile" ]; then
#        exit 1
#    fi
#fi
#
#if [ ! -d "/var/lib/mysql/wordpress" ]; then
#    cat << EOF > /tmp/create_db.sql
#USE mysql;
#FLUSH PRIVILEGES;
#DELETE FROM mysql.user WHERE User='';
#DROP DATABASE IF EXISTS test;
#DELETE FROM mysql.db WHERE Db='test';
#DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
#ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASS}';
#CREATE DATABASE '${DB_NAME}' CHARACTER SET utf8 COLLATE utf8_general_ci;
#CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASS}';
#GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
#FLUSH PRIVILEGES;
#EOF
#
#    # Run init.sql
#    /usr/sbin/mysqld --user=mysql --init-file=/tmp/create_db.sql & sleep 5
#    rm -f /tmp/create_db.sql
#
#fi
#