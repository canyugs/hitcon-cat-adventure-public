FROM ubuntu:20.04
RUN apt update -y
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata
RUN apt install socat -y
COPY ./chal /root/chal
RUN chmod +x /root/chal/chal
WORKDIR /root/chal

EXPOSE 10000
ENTRYPOINT socat tcp-l:10000,fork exec:./chal,reuseaddr
