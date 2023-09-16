FROM ubuntu:20.04
RUN apt update -y
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata
RUN apt install apache2 php -y
RUN echo "AddDefaultCharset utf-8" > /etc/apache2/conf-available/charset.conf
COPY ./chal /var/www/html/

CMD service apache2 start && tail -F /dev/null
EXPOSE 80
