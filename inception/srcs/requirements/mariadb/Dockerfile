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
