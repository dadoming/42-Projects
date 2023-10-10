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
    curl \
    iputils-ping \
    unzip && \
    rm -rf /var/lib/apt/lists/*

# Create the directory for the PID and socket file
# Configure PHP-FPM
RUN mkdir -p /run/php
RUN mkdir -p /var/www/html

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

RUN touch /run/php/php${PHP_VERSION}-fpm.pid
# Create wp-config.php
## Atualizar isto para fazer copy no docker compose

COPY ./requirements/wordpress/conf/www.conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf

COPY ./requirements/wordpress/conf/wp-config.php /tmp/wp-config.php

WORKDIR /var/www/html


COPY ./requirements/wordpress/conf/wp_config_create.sh .
RUN chmod +x /var/www/html/wp_config_create.sh && \
    ./wp_config_create.sh


# Set filesytem permissions
RUN chmod -R 0777 /var/www/html/wordpress/wp-content/

CMD ["php-fpm7.4", "-F", "-R"]
