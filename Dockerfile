FROM ubuntu:22.04

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential gdb nasm strace ltrace valgrind libcriterion-dev

WORKDIR /tmp/build

COPY . .

CMD ["make", "test"]
# RUN make test