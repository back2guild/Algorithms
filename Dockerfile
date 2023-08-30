FROM ubuntu:22.04

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential gdb

COPY . /tmp
WORKDIR /tmp

RUN make clean

RUN make test