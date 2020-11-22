FROM nginx

RUN mkdir -p /www/data

WORKDIR /www/data
COPY conf/darons.io.conf /etc/nginx/conf.d
COPY build .