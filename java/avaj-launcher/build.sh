#!/usr/bin/bash

sudo docker build -t gertvdijk/java7 .
sudo docker run --rm -it gertvdijk/java7 -version
