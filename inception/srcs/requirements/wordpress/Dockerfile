FROM debian:11

ARG PHP_VERSION=7.4
ARG DB_NAME
ARG DB_USER
ARG DB_PASS

# Install PHP and required extensions
RUN apt-get update && apt-get install -y \
    php${PHP_VERSION} \
    php${PHP_VERSION}-fpm \
    php${PHP_VERSION}-mysqli \
    php${PHP_VERSION}-json \
    php${PHP_VERSION}-curl \
    php${PHP_VERSION}-dom \
    php${PHP_VERSION}-mbstring \
    php${PHP_VERSION}-zip \
    php${PHP_VERSION}-redis \
    wget \
    unzip && \
    rm -rf /var/lib/apt/lists/*

# Create the directory for the PID and socket file
# Configure PHP-FPM
RUN mkdir -p /run/php
RUN mkdir -p /var/www/html

# Download and install WordPress
RUN wget https://wordpress.org/latest.zip && \
    unzip latest.zip -d wordpress && \
    cp -rf wordpress/* /var/www/html/wordpress && \
    rm -rf wordpress latest.gz

RUN rm /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf

RUN touch /run/php/php${PHP_VERSION}-fpm.pid
# Create wp-config.php
## Atualizar isto para fazer copy no docker compose

COPY ./requirements/wordpress/conf/www.conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf

COPY ./requirements/wordpress/conf/wp-config.php /var/www/html/wordpress/wp-config.php

WORKDIR /var/www/html

RUN chown -R www-data:www-data /var/www/html && \
    chmod -R 755 /var/www/html

EXPOSE 9000

CMD ["php-fpm7.4", "-F", "-R"]
