FROM ubuntu:20.04
RUN apt update -y
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata
RUN apt install apache2 php -y
COPY ./chal /var/www/html/

CMD service apache2 start && tail -F /dev/null
EXPOSE 80
