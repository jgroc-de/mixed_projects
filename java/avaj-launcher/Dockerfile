FROM ubuntu:trusty
RUN apt-get update \
    && apt-get install -y \
        openjdk-7-jdk \
    && rm -rf /var/lib/apt/lists/*

ENTRYPOINT ["/usr/bin/javac"]
