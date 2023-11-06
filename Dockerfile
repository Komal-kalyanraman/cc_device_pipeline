
FROM ubuntu:20.04 AS ubuntu

#
# Identify the maintainer of an image
LABEL maintainer="komala.yerra@wipro.com"

#
# Update the image to the latest packages
RUN apt-get update \
    && apt-get install -y nano \
    && apt-get install -y g++ \
    && apt-get install -y build-essential

ARG CMAKE_VERSION=3.16.3

RUN apt-get update && apt-get install -y build-essential libssl-dev wget \
    && wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}.tar.gz \
    && tar zxvf cmake-${CMAKE_VERSION}.tar.gz \
    && cd cmake-${CMAKE_VERSION} \
    && ./bootstrap \
    && make && make install && cd .. \
    && rm -rf /cmake-${CMAKE_VERSION} && rm cmake-${CMAKE_VERSION}.tar.gz \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

RUN apt-get update \
    && apt-get install -y zip

RUN apt-get update \
    && apt-get -y install nlohmann-json3-dev
 
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

ENV TZ=Asia/Singapore
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --fix-missing \
    && apt-get install -y -f libopencv-dev

COPY code ./code

WORKDIR /code

#
# Last is the actual command
ENTRYPOINT ["tail", "-f", "/dev/null"]
