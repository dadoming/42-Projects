FROM debian:11

# Update and upgrade packages, install nginx, curl and remove apt cache by removing the lists folder.
#  Removing the lists folder is a common practice to reduce the image size.
RUN apt-get update && apt-get install -y nginx curl wget && rm -rf /var/lib/apt/lists/*

# Download mkcert and make it executable
#  Create a self-signed certificate for dadoming.42.fr and insert it in the ssl folder
#   Remove mkcert after use
RUN curl -s https://api.github.com/repos/FiloSottile/mkcert/releases/latest | grep browser_download_url | grep linux-amd64 | cut -d '"' -f 4 | wget -qi - \
    && mv mkcert-v*-linux-amd64 mkcert \
    && chmod a+x mkcert \
    && mv mkcert /usr/local/bin/ \
    && mkdir -p /etc/nginx/ssl \
    && mkcert -cert-file /etc/nginx/ssl/dadoming.crt -key-file /etc/nginx/ssl/dadoming.key dadoming.42.fr \
    && rm -rf mkcert

# Expose port 443 to exchange traffic through https
EXPOSE 443

# To start: sudo systemctl start nginx
CMD ["nginx", "-g", "daemon off;"]