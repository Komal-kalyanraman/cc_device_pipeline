
FROM ubuntu:20.04 AS ubuntu

#
# Identify the maintainer of an image
LABEL maintainer="komala.yerra@wipro.com"

#
# Update the image to the latest packages
RUN apt-get update
RUN apt-get install nano -y
# RUN apt install -y cmake

COPY code ./code

WORKDIR /code

#
# Last is the actual command
ENTRYPOINT ["tail", "-f", "/dev/null"]
