FROM ubuntu:20.04
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata
RUN apt-get install socat vim -y
COPY ./chal /root/chal
WORKDIR /root/chal
RUN chmod +x chal.sh
RUN useradd -ms /bin/bash user

EXPOSE 10003
ENTRYPOINT su user -Pc "socat tcp-l:10003,fork exec:'./chal.sh',reuseaddr"
