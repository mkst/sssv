FROM ubuntu:22.04 AS build

ENV DEBIAN_FRONTEND=noninteractive

COPY /packages.txt /

RUN apt-get update && \
    apt-get install -y $(cat /packages.txt) && \
    rm -rf /var/lib/apt/lists/*

COPY requirements.txt /

RUN python3 -m pip install -r /requirements.txt --no-cache-dir --disable-pip-version-check

COPY .bash_aliases /root/.bash_aliases

RUN mkdir /sssv
WORKDIR /sssv
