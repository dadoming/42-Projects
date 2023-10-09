FROM debian:11

RUN apt-get update && apt-get install -y mariadb-server && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld
RUN mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chmod 777 /var/run/mysqld

COPY requirements/mariadb/tools/create_db.sh .
RUN chmod 777 /create_db.sh

EXPOSE 3306

ENTRYPOINT ./create_db.sh

##############################################


#FROM debian:11
#
#RUN apt update \
#    && apt install mariadb-server procps -y

#COPY requirements/mariadb/tools/create_db.sh .

#COPY requirements/mariadb/conf/db_script.sql /etc/mysql/conf.d/
#RUN chmod +x /create_db.sh
#WORKDIR /var/lib/mysql

#ENTRYPOINT ["bash", "-c", "/create_db.sh"]

############################################################

#FROM debian:11
#
#ARG DB_NAME
#ARG DB_USER
#ARG DB_PASS
#
## Install MariaDB and other required packages
#RUN apt-get update && apt-get install -y mariadb-server mariadb-client && rm -rf /var/lib/apt/lists/*
#
## Create directories and configure MariaDB
#RUN mkdir -p /var/run/mysqld && chmod 777 /var/run/mysqld && \
#    { echo '[mysqld]'; \
#      echo 'skip-host-cache'; \
#      echo 'skip-name-resolve'; \
#      echo 'bind-address=0.0.0.0'; \
#    } | tee /etc/mysql/conf.d/docker.cnf && \
#    sed -i 's/bind-address\s*=\s*127.0.0.1/skip-networking=0/' /etc/mysql/mariadb.conf.d/50-server.cnf
#
## Initialize the MariaDB data directory
#RUN mysqld_safe --skip-networking
## --skip-grant-tables add to the server file
## https://stackoverflow.com/questions/1708409/how-to-start-mysql-with-skip-grant-tables
#
## Copy the create_db.sh script and run it
#COPY requirements/mariadb/tools/create_db.sh /create_db.sh
#RUN chmod +x /create_db.sh && sh create_db.sh
#
## Switch to the mysql user and start MariaDB
#USER mysql
#CMD ["/usr/sbin/mysqld", "--skip-log-error"]