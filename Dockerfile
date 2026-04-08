FROM ubuntu:24.04 AS build

ENV DEBIAN_FRONTEND=noninteractive

COPY packages.txt /

RUN apt-get update && \
    apt-get install -y --no-install-recommends $(cat /packages.txt) && \
    rm -rf /var/lib/apt/lists/*

COPY requirements.txt /
RUN python3 -m pip install -r /requirements.txt --no-cache-dir --disable-pip-version-check --break-system-packages

COPY tools/splat/requirements.txt /splat-requirements.txt
RUN python3 -m pip install -r /splat-requirements.txt --no-cache-dir --disable-pip-version-check --break-system-packages


COPY .bash_aliases /home/ubuntu/.bash_aliases

RUN mkdir /sssv
WORKDIR /sssv

USER ubuntu
