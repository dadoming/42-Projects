FROM debian:11

# Install mariadb and mariadb-client
RUN apt-get update && apt-get install -y mariadb-server mariadb-client && rm -rf /var/lib/apt/lists/*

CMD [ "mysql", "-u", "root", "-p", "1", "-h", "127.0.0.1" ]