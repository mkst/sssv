FROM ubuntu:20.04 as build

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y \
      binutils-mips-linux-gnu \
      build-essential \
      less \
      libglib2.0 \
      python3 \
      python3-pip \
      unzip \
      wget

COPY requirements.txt /

RUN python3 -m pip install -r /requirements.txt

RUN mkdir /sssv
WORKDIR /sssv
