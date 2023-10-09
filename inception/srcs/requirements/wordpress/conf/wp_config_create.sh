#!/bin/sh

# WordPress installation
if [ -f ./wp-config.php ]
then
	echo "WordPress already installed"
else
	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	rm -rf latest.tar.gz

	cd wordpress
	
	cp ../../../../tmp/wp-config.php .
	wp core install --allow-root --url=${DOMAIN} --title="Inception" --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASS} --admin_email=${WP_ADMIN_EMAIL}
	wp user create --allow-root ${WP_USER} ${WP_USER_EMAIL} --user_pass=${WP_USER_PASS};
fi

exec "$@"