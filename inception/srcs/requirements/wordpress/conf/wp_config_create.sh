#!/bin/sh

# WordPress installation
if [ -f ./wp-config.php ]
then
	echo "WordPress already installed"
else
	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	mv wordpress/* .
	rm -rf latest.tar.gz wordpress
	
	sed -i "s/username_here/${DB_USER}/g" wp-config-sample.php
	sed -i "s/password_here/$DB_PASS/g" wp-config-sample.php
	sed -i "s/localhost/$DB_NAME/g" wp-config-sample.php
	sed -i "s/database_name_here/$DB_HOST/g" wp-config-sample.php
	cp wp-config-sample.php wp-config.php
	wp core install --allow-root --url=${DOMAIN} --title="Inception" --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASS} --admin_email=${WP_ADMIN_EMAIL}
	wp user create --allow-root ${WP_USER} ${WP_USER_EMAIL} --user_pass=${WP_USER_PASS};
fi

exec "$@"