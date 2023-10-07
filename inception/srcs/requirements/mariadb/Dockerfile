FROM debian:11

ARG DB_NAME
ARG DB_USER
ARG DB_PASS
ARG DB_ROOT

# Install MariaDB and other required packages
RUN apt-get update && apt-get install -y mariadb-server mariadb-client && rm -rf /var/lib/apt/lists/*

# Create directories and configure MariaDB
RUN mkdir -p /var/run/mysqld && chmod 777 /var/run/mysqld && \
    { echo '[mysqld]'; \
      echo 'skip-host-cache'; \
      echo 'skip-name-resolve'; \
      echo 'bind-address=0.0.0.0'; \
    } | tee /etc/mysql/conf.d/docker.cnf && \
    sed -i "s|skip-networking|skip-networking=0|g" /etc/mysql/mariadb.conf.d/50-server.cnf

# Initialize the MariaDB data directory
RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

# Expose port 3306
EXPOSE 3306

# Copy the create_db.sh script and run it
COPY requirements/mariadb/tools/create_db.sh /create_db.sh
RUN chmod +x /create_db.sh && sh create_db.sh

# Switch to the mysql user and start MariaDB
USER mysql
CMD ["/usr/sbin/mysqld", "--skip-log-error"]