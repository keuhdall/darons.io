FROM caddy:2.1.1-alpine

RUN mkdir -p /www/data

WORKDIR /www/data
COPY conf/Caddyfile /etc/caddy/Caddyfile
COPY build .