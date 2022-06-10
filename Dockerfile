FROM ubuntu:22.04 as binutils

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y wget build-essential texinfo

ARG BINUTILS_VERSION=2.34
ARG BINUTILS_SHA1SUM=361566c9ab5e90bd847d06f46fb9f18ec6c3ecf0

RUN wget https://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_VERSION}.tar.bz2 && \
  echo "${BINUTILS_SHA1SUM}  binutils-${BINUTILS_VERSION}.tar.bz2" | sha1sum --check && \
  tar xvjf binutils-${BINUTILS_VERSION}.tar.bz2 && \
  cd /binutils-${BINUTILS_VERSION} && \
  ./configure --target=mips-elf && \
  make --jobs 4 && \
  make install

FROM ubuntu:22.04 as build

ENV DEBIAN_FRONTEND=noninteractive

COPY /packages.txt /

RUN apt-get update && \
    apt-get install -y $(cat /packages.txt) && \
    rm -rf /var/lib/apt/lists/*

COPY requirements.txt /

RUN python3 -m pip install -r /requirements.txt --no-cache-dir

COPY .bash_aliases /root/.bash_aliases

COPY --from=binutils /usr/local/bin/mips-elf-* /usr/local/bin/

RUN mkdir /sssv
WORKDIR /sssv

ENV TERM=xterm-256color
