FROM ubuntu:20.04 as build

ENV DEBIAN_FRONTEND=noninteractive

COPY /packages.txt /

RUN apt-get update && \
    apt-get install -y $(cat /packages.txt) && \
    rm -rf /var/lib/apt/lists/*

COPY requirements.txt /

RUN python3 -m pip install -r /requirements.txt --no-cache-dir

COPY .bash_aliases /root/.bash_aliases

RUN mkdir /sssv
WORKDIR /sssv

ENV TERM=xterm-256color
