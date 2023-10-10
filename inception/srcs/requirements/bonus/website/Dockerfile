FROM debian:11

RUN apt-get update && apt-get install -y nginx curl wget && rm -rf /var/lib/apt/lists/*

RUN echo "server {" > /etc/nginx/conf.d/default.conf && \
    echo "root    /var/www;" >> /etc/nginx/conf.d/default.conf && \
    echo "location / {" >> /etc/nginx/conf.d/default.conf && \
    echo "    try_files \$uri /index.html;" >> /etc/nginx/conf.d/default.conf && \
    echo "}}" >> /etc/nginx/conf.d/default.conf

COPY requirements/bonus/website/conf/* /var/www/html/

EXPOSE 80
CMD ["nginx", "-g", "daemon off;"]