if [ -d "/var/lib/mysql/$DB_NAME" ] 
then
    echo "Database already exists"
else
mysql_install_db
service mariadb start
mysql_secure_installation << EOF

n
Y
$DB_ROOT_PASS
$DB_ROOT_PASS
Y
n
Y
Y
EOF
# Create database
# select user from mysql.user;
mysql -u root -p"$DB_ROOT_PASS" -e "CREATE DATABASE IF NOT EXISTS $DB_NAME;" && \
mysql -u root -p"$DB_ROOT_PASS" -e "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';" && \
mysql -u root -p"$DB_ROOT_PASS" -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';" && \
mysql -u root -p"$DB_ROOT_PASS" -e "FLUSH PRIVILEGES;" && \
mysql -u root -p"$DB_ROOT_PASS" -e "DELETE FROM mysql.user WHERE User='root'; FLUSH PRIVILEGES;"
sleep 5
service mariadb stop
fi
# Replace current shell process to mysqld_safe and accept connections from all
exec mysqld_safe --bind-address=0.0.0.0
