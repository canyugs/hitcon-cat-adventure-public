FROM debian:stable
RUN apt update
RUN apt install -y openssl curl
COPY rootCA.crt /etc/ssl/private/rootCA.crt
COPY rootCA.key /etc/ssl/private/rootCA.key
ENTRYPOINT /bin/bash
