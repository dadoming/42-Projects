FROM debian:11

# Install mariadb and mariadb-client, also create the folder where the socket will be
## also set ownership and permissions for the folder for mysql user
RUN apt-get update && apt-get install -y mariadb-server mariadb-client && rm -rf /var/lib/apt/lists/*

COPY requirements/mariadb/conf/mariadb.cnf /etc/mysql/mariadb.conf.d/

EXPOSE 3306

COPY requirements/mariadb/tools/setup.sh /

RUN chmod +x /setup.sh

CMD ["/setup.sh"]
