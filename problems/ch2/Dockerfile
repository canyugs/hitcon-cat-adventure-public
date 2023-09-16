FROM ubuntu:20.04
RUN apt update -y
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata
RUN apt install socat -y
COPY ./chal /root/chal
RUN chmod +x /root/chal/chal
WORKDIR /root/chal
RUN useradd -ms /bin/bash user

EXPOSE 10001
ENTRYPOINT su user -c "socat tcp-l:10001,fork exec:./chal,reuseaddr"
