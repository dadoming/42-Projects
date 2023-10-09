if [ -d "/var/lib/mysql/$DB_NAME" ] 
then
    echo "Database already exists"
else

mysql_install_db

service mariadb start

# Set root to not login without pass
mysql_secure_installation << _EOF_

Y
$DB_ROOT_PASS
$DB_ROOT_PASS
Y
n
Y
Y
_EOF_

# Create database
echo "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';" | mysql -u root -p $DB_ROOT_PASS
echo "CREATE DATABASE IF NOT EXISTS $DB_NAME; GRANT ALL ON $DB_NAME.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS'; FLUSH PRIVILEGES;" | mysql -u root -p $DB_ROOT_PASS


fi 

sleep 2

service mariadb stop

exec mysqld_safe --bind-address=0.0.0.0
